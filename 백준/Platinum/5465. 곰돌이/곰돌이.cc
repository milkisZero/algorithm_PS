#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
using ll = long long;
using pci = pair<char, int>;
using pii = pair<int, int>;

pci arr[803][803];
int visited[803][803];
int n, s;
pii pointM;
queue<pii> q;

void bfs() {
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        pii tmp[4] = {{cur.first + 1, cur.second},
                      {cur.first - 1, cur.second},
                      {cur.first, cur.second + 1},
                      {cur.first, cur.second - 1}};

        for (int i = 0; i < 4; i++) {
            if (tmp[i].first < 0 || tmp[i].first >= n || tmp[i].second < 0 || tmp[i].second >= n)
                continue;

            if (!visited[tmp[i].first][tmp[i].second]) {
                if (arr[tmp[i].first][tmp[i].second].first == 'G' || arr[tmp[i].first][tmp[i].second].first == 'M') {
                    visited[tmp[i].first][tmp[i].second] = 1;
                    arr[tmp[i].first][tmp[i].second].second = arr[cur.first][cur.second].second + 1;
                    q.push({tmp[i].first, tmp[i].second});
                }
            }
        }
    }
}

int bfs2(int limit) {
    queue<pair<pii, int>> mq;
    mq.push({pointM, 0});
    memset(visited, 0, sizeof(visited));
    visited[pointM.first][pointM.second] = 1;

    if (arr[pointM.first][pointM.second].second <= limit)
        return 0;

    while (!mq.empty()) {
        pii cur = mq.front().first;
        int cnt = mq.front().second;
        mq.pop();

        pii tmp[4] = {{cur.first + 1, cur.second},
                      {cur.first - 1, cur.second},
                      {cur.first, cur.second + 1},
                      {cur.first, cur.second - 1}};

        for (int i = 0; i < 4; i++) {
            if (tmp[i].first < 0 || tmp[i].first >= n || tmp[i].second < 0 || tmp[i].second >= n)
                continue;

            if (arr[tmp[i].first][tmp[i].second].first == 'D')
                return 1;
            else if (!visited[tmp[i].first][tmp[i].second] && arr[tmp[i].first][tmp[i].second].second > (cnt + 1) / s + limit) {
                if (arr[tmp[i].first][tmp[i].second].first == 'G') {
                    visited[tmp[i].first][tmp[i].second] = 1;
                    mq.push({{tmp[i].first, tmp[i].second}, cnt + 1});
                }
            }
        }
    }
    return 0;
}

int bs() {
    int l = 0, r = n * n, m, res = -1;
    while (l <= r) {
        m = (l + r) / 2;

        if (bfs2(m)) {
            l = m + 1;
            res = max(res, m);
        }
        else
            r = m - 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j].first;
            arr[i][j].second = 0;

            if (arr[i][j].first == 'M')
                pointM = {i, j};
            else if (arr[i][j].first == 'H')
                q.push({i, j});
        }
    }

    bfs();
    cout << bs() << '\n';

    return 0;
}