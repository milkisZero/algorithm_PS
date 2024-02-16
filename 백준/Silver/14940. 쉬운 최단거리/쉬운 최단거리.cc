#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int arr[1003][1003];
int visited[1003][1003];

void bfs(int a, int b) {
    fill(&visited[0][0], &visited[n + 1][m + 1], -1);
    visited[a][b] = 0;
    queue<pair<pi, int>> q;
    q.push({{a, b}, 0});

    while (!q.empty()) {
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int cnt = q.front().second + 1;
        q.pop();

        for (int i = -1; i <= 1; i += 2) {
            if ((curX + i >= 0 && curX + i < n) && visited[curX + i][curY] == -1 && arr[curX + i][curY] != 0) {
                visited[curX + i][curY] = cnt;
                q.push({{curX + i, curY}, cnt});
            }
            if ((curY + i >= 0 && curY + i < m) && visited[curX][curY + i] == -1 && arr[curX][curY + i] != 0) {
                visited[curX][curY + i] = cnt;
                q.push({{curX, curY + i}, cnt});
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                a = i;
                b = j;
            }
        }
    }

    bfs(a, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0)
                cout << 0 << ' ';
            else
                cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}