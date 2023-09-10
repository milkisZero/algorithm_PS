#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[1003][1003];
int visited[1003][1003];
pii start;
int res, l, r, n, m;

void bfs() {
    visited[start.first][start.second] = 1;
    res++;

    queue<pair<pii, pii>> q;
    q.push({start, {0, 0}});
    while (!q.empty()) {
        pii cur = q.front().first;
        pii direc = q.front().second;
        q.pop();

        for (int i = cur.first; i <= n + 1; i++) {
            if (!visited[i][cur.second]) {
                if (arr[i][cur.second] == 0) {
                    q.push({{i, cur.second}, direc});
                    res++;
                    visited[i][cur.second] = 1;
                }
                else
                    break;
            }
        }

        for (int i = cur.first; i >= 0; i--) {
            if (!visited[i][cur.second]) {
                if (arr[i][cur.second] == 0) {
                    q.push({{i, cur.second}, direc});
                    res++;
                    visited[i][cur.second] = 1;
                }
                else
                    break;
            }
        }

        pii tmp[2] = {{cur.first, cur.second + 1},
                      {cur.first, cur.second - 1}};

        for (int i = 0; i < 2; i++) {
            if (!visited[tmp[i].first][tmp[i].second]) {
                if (arr[tmp[i].first][tmp[i].second] == 0) {
                    if (i == 0) {
                        if (direc.second + 1 <= r) {
                            q.push({tmp[i], {direc.first, direc.second + 1}});
                            res++;
                            visited[tmp[i].first][tmp[i].second] = 1;
                        }
                    }
                    else {
                        if (direc.first + 1 <= l) {
                            q.push({tmp[i], {direc.first + 1, direc.second}});
                            res++;
                            visited[tmp[i].first][tmp[i].second] = 1;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> l >> r;

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
                arr[i][j] = -1;
                continue;
            }

            char tmp;
            cin >> tmp;
            arr[i][j] = tmp + 1 - '1';
            if (arr[i][j] == 2)
                start = {i, j};
        }
    }

    bfs();
    cout << res;

    return 0;
}