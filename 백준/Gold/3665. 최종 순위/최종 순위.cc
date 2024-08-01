#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<ll> topo(ll n, vector<ll> g[505], int ind[505]) {
    queue<ll> q;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) q.push(i);
    }

    vector<ll> res;

    while (!q.empty()) {
        ll a = q.front();
        q.pop();

        res.push_back(a);

        for (int i = 0; i < g[a].size(); i++) {
            ll next = g[a][i];
            ind[next]--;
            if (!ind[next]) q.push(next);
        }
    }

    return res;
}

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n;

        vector<ll> g[505];
        int ind[505] = {0};

        vector<ll> v(n);
        for (auto &e : v) cin >> e;

        cin >> m;
        map<pll, bool> mp;
        for (int i = 0; i < m; i++) {
            ll a, b;
            cin >> a >> b;

            mp[{a, b}] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll a = v[i], b = v[j];
                if (a > b) swap(a, b);
                if (mp.find({a, b}) != mp.end()) {
                    g[v[i]].push_back(v[j]);
                    ind[v[j]]++;
                }
                else {
                    g[v[j]].push_back(v[i]);
                    ind[v[i]]++;
                }
            }
        }

        vector<ll> res = topo(n, g, ind);
        if (res.size() < n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for (int i = n - 1; i >= 0; i--) cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}