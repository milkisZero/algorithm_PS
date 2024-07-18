#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<ll> v[100005];
ll visited[100005];

void dfs(ll cur, ll dep) {
    visited[cur] = dep;

    sort(v[cur].begin(), v[cur].end(), greater<>());

    for (auto e : v[cur]) {
        if (-1 == visited[e]) dfs(e, dep + 1);
    }
}

int main() {
    fastio;

    ll n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visited, -1, sizeof(visited));
    dfs(r, 0);

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}