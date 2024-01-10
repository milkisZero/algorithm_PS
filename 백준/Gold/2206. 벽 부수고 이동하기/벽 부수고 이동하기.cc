#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;
string map[1003];
pii visited[1003][1003];
int n, m;
int res = -1;

void bfs() {
    visited[0][0].first = 1;
    visited[0][0].second = 0;
    queue<pii> q;
    q.push({0, 0});

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        int val = visited[curX][curY].first;
        int cnt = visited[curX][curY].second;
        q.pop();

        if (curX == n - 1 && curY == m - 1) {
            res = visited[n - 1][m - 1].first;
            return;
        }

        for (int i = -1; i <= 1; i++) {
            if ((curX + i >= 0 && curX + i < n)) {
                if (map[curX + i][curY] == '0') {
                    if (!visited[curX + i][curY].first || (visited[curX + i][curY].second == 1 && cnt == 0)) {
                        q.push({curX + i, curY});
                        visited[curX + i][curY].first = val + 1;
                        visited[curX + i][curY].second = cnt;
                    }
                }
                else {
                    if (cnt == 0 && (!visited[curX + i][curY].first || (visited[curX + i][curY].second == 1 && cnt == 0))) {
                        q.push({curX + i, curY});
                        visited[curX + i][curY].first = val + 1;
                        visited[curX + i][curY].second = cnt + 1;
                    }
                }
            }
            if ((curY + i >= 0 && curY + i < m)) {
                if (map[curX][curY + i] == '0') {
                    if (!visited[curX][curY + i].first || (visited[curX][curY + i].second == 1 && cnt == 0)) {
                        q.push({curX, curY + i});
                        visited[curX][curY + i].first = val + 1;
                        visited[curX][curY + i].second = cnt;
                    }
                }
                else {
                    if (cnt == 0 && (!visited[curX][curY + i].first || (visited[curX][curY + i].second == 1 && cnt == 0))) {
                        q.push({curX, curY + i});
                        visited[curX][curY + i].first = val + 1;
                        visited[curX][curY + i].second = cnt + 1;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    bfs();

    if (res == 0)
        cout << -1;
    else
        cout << res;

    return 0;
}