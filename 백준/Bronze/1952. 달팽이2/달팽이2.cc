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

vector<ll> v[102];
ll m, n;
ll visited[102][102];
pll mov[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
ll idx, cnt;

bool inmap(ll r, ll c) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

void dfs(ll r, ll c) {
    visited[r][c] = 1;

    ll nx = r + mov[idx].first, ny = c + mov[idx].second;
    if (inmap(nx, ny) && visited[nx][ny] == 0) {
        dfs(nx, ny);
    }
    else {
        idx = (idx + 1) % 4;
        nx = r + mov[idx].first, ny = c + mov[idx].second;
        if (inmap(nx, ny) && visited[nx][ny] == 0) {
            cnt++;
            dfs(nx, ny);
        }
    }
}

int main() {
    fastio;

    cin >> m >> n;
    for (int i = 0; i < m; i++) v[i].resize(n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = 1;
        }
    }

    dfs(0, 0);
    cout << cnt;

    return 0;
}