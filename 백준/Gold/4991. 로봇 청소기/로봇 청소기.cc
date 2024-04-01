#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

string s[21];
pi add[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
ll w, h, k, res = LLINF;
int num[21][21];
ll visi[21][21][1 << 10];

bool in_map(ll x, ll y) {
    if (x >= h || y >= w || x < 0 || y < 0)
        return 0;
    return 1;
}

void bfs(ll x0, ll y0) {
    visi[x0][y0][0] = 1;

    queue<pair<pll, ll>> q;
    q.push({{x0, y0}, 0});

    while (!q.empty()) {
        auto [x, y] = q.front().first;
        ll state = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            auto [a, b] = add[i];
            ll nx = x + a, ny = y + b;
            if (in_map(nx, ny) && s[nx][ny] != 'x') {
                ll tmp = state;
                if (s[nx][ny] == '*')
                    tmp |= (1 << num[nx][ny]);

                if (visi[nx][ny][tmp] == 0) {
                    visi[nx][ny][tmp] = visi[x][y][state] + 1;
                    q.push({{nx, ny}, tmp});
                }

                if ((1 << k) - 1 == tmp)
                    res = min(res, visi[nx][ny][tmp]);
            }
        }
    }
}

int main() {
    fastio;

    while (1) {
        cin >> w >> h;
        if (!w && !h)
            break;

        ll x, y;
        for (int i = 0; i < h; i++) {
            cin >> s[i];
            for (int j = 0; j < w; j++) {
                if (s[i][j] == 'o')
                    x = i, y = j;
                else if (s[i][j] == '*')
                    num[i][j] = k++;
            }
        }

        bfs(x, y);

        if (res == LLINF)
            cout << -1 << '\n';
        else
            cout << res - 1 << '\n';
        memset(visi, 0, sizeof(visi));
        k = 0, res = LLINF;
    }

    return 0;
}