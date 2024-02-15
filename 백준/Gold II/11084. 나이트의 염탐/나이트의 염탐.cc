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
#define MOD 1000000009

int visited[404][404], dp[404][404];
int r, c;

typedef struct info {
    int x, y, val;
} INFO;

void bfs() {
    dp[1][1] = 1;
    visited[1][1] = 0;

    queue<INFO> q;
    q.push({1, 1, 0});

    while (!q.empty()) {
        int curX = q.front().x, curY = q.front().y;
        int cnt = q.front().val;
        q.pop();
        vector<pi> v;
        v.push_back({curX + 2, curY + 1});
        v.push_back({curX + 2, curY - 1});
        v.push_back({curX + 1, curY + 2});
        v.push_back({curX - 1, curY + 2});
        v.push_back({curX + 1, curY - 2});
        v.push_back({curX - 1, curY - 2});
        v.push_back({curX - 2, curY + 1});
        v.push_back({curX - 2, curY - 1});

        for (auto e : v) {
            if (e.first >= 1 && e.second >= 1 && e.first <= r && e.second <= c) {
                if (visited[e.first][e.second] == 0 || visited[e.first][e.second] >= cnt + 1) {
                    if (dp[e.first][e.second] == 0)
                        q.push({e.first, e.second, cnt + 1});
                    dp[e.first][e.second] = (dp[e.first][e.second] + dp[curX][curY]) % MOD;
                    visited[e.first][e.second] = cnt + 1;
                }
                else if (e.first == r && e.second == c)
                    break;
            }
        }
    }
}

int main() {
    fastio;

    cin >> r >> c;

    bfs();

    if (dp[r][c] == 0)
        cout << "None";
    else
        cout << visited[r][c] << ' ' << dp[r][c];

    return 0;
}