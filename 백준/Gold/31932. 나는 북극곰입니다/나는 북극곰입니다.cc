#include <bits/stdc++.h>
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pair<ll, pll>> e[100006];
ll d[100006];
ll n, m;

int main() {
    fastio;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll u, v, d, t;
        cin >> u >> v >> d >> t;
        e[u].push_back({v, {d, t}});
        e[v].push_back({u, {d, t}});
    }

    fill(d, d + n + 3, -1);

    priority_queue<pll> pq;
    pq.push({0, n});
    d[n] = 0;

    while (!pq.empty()) {
        auto [val, x] = pq.top();
        pq.pop();

        if (d[x] != val) continue;

        for (auto [v, info] : e[x]) {
            auto [ddd, t] = info;

            ll k = (x == n) ? t : val;
            k = min(k, t);

            if (d[v] < k - ddd && k - ddd >= 0) {
                d[v] = k - ddd;
                if (v != 1) pq.push({d[v], v});
            }
        }
    }

    cout << d[1];

    return 0;
}