#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll n, m, res = 0;
vector<ll> v[9], v2[9];
ll visited[9][9];
pll mov[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool inmap(ll a, ll b) {
    return (a < 0 || b < 0 || a >= n || b >= m) ? 0 : 1;
}

void bfs(ll a, ll b) {
    queue<pll> q;
    visited[a][b] = 1;
    q.push({a, b});

    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();

        for (auto [x, y] : mov) {
            if (inmap(a + x, b + y) && v2[a + x][b + y] != 1 && visited[a + x][b + y] == 0) {
                v2[a + x][b + y] = 2;
                visited[a + x][b + y] = 1;
                q.push({a + x, b + y});
            }
        }
    }
}

void check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v2[i][j] = v[i][j];
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && v2[i][j] == 2)
                bfs(i, j);
        }
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v2[i][j] == 0) cnt++;
        }
    }
    res = max(res, cnt);
}

void bf(ll a, ll b, ll cnt) {
    if (cnt == 3) {
        check();
        return;
    }

    for (int i = a; i < n; i++) {
        for (int j = i == a ? b : 0; j < m; j++) {
            if (v[i][j] == 0) {
                v[i][j] = 1;
                bf(i, j, cnt + 1);
                v[i][j] = 0;
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        v[i].resize(m);
        v2[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    bf(0, 0, 0);

    cout << res;

    return 0;
}