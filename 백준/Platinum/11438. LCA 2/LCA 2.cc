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
ll depth[100005];
ll parent[100005][20];

void dfs(ll cur) {
    for (auto e : v[cur]) {
        if (e != 1 && !depth[e]) {
            depth[e] = depth[cur] + 1;
            parent[e][0] = cur;
            dfs(e);
        }
    }
}

int main() {
    fastio;

    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));
    dfs(1);

    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != -1) parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    ll m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;

        if (depth[a] < depth[b]) swap(a, b);
        ll k = depth[a] - depth[b];

        for (int j = 0; k; j++) {
            if (k & 1) a = parent[a][j];
            k >>= 1;
        }

        if (a != b) {
            for (int j = 19; j >= 0; j--) {
                if (parent[a][j] != -1 && parent[a][j] != parent[b][j]) {
                    a = parent[a][j];
                    b = parent[b][j];
                }
            }
            a = parent[a][0];
        }

        cout << a << '\n';
    }

    return 0;
}