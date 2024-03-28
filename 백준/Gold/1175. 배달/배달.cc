#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

string s[55];
pi add[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, res = INF;

typedef struct info {
    int x, y, dir;
} info;

int func(int a, int b, int c, int d) {
    int visited[55][55][5] = {0};
    if (c)
        visited[a][b][d] = 1;
    queue<info> q;
    q.push({a, b, d});
    while (!q.empty()) {
        auto [x, y, dir] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            auto [a1, a2] = add[i];
            if (x + a1 < 0 || x + a1 >= n)
                continue;
            if (y + a2 < 0 || y + a2 >= m)
                continue;

            if (i != dir && visited[x + a1][y + a2][i] == 0 && s[x + a1][y + a2] != '#') {
                if (s[x + a1][y + a2] == 'C') {
                    if (c == 1 && (a != x + a1 || b != y + a2)) {
                        return visited[x][y][dir];
                    }
                    if (c == 0) {
                        int k = func(x + a1, y + a2, 1, i);
                        if (k != -1) {
                            res = min(res, visited[x][y][dir] + 1 + k);
                            continue;
                        }
                    }
                }

                visited[x + a1][y + a2][i] = visited[x][y][dir] + 1;
                q.push({x + a1, y + a2, i});
            }
        }
    }
    return -1;
}

int main() {
    fastio;

    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S')
                x = i, y = j;
        }
    }

    func(x, y, 0, 4);
    if (res == INF)
        cout << -1;
    else
        cout << res;

    return 0;
}