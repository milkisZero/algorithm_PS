#include <bits/stdc++.h>
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pair<ll, pll>> e[100006];
ll d[100006];
ll n, m;

ll calc(ll time) {

    fill(d, d + n + 3, LLINF);

    priority_queue<pll> pq;
    pq.push({-time, 1});
    d[1] = time;

    while (!pq.empty()) {
        auto [val, x] = pq.top();
        pq.pop();
        val = -val;

        if (d[x] != val) continue;

        for (auto [v, info] : e[x]) {
            auto [ddd, t] = info;
            if (d[v] > val + ddd && val + ddd <= t) {
                d[v] = val + ddd;
                pq.push({-d[v], v});

                if (n == v) return 1;
            }
        }
    }

    return 0;
}

int main() {
    fastio;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll u, v, d, t;
        cin >> u >> v >> d >> t;
        e[u].push_back({v, {d, t}});
        e[v].push_back({u, {d, t}});
    }

    ll res = -1;
    ll l = 0, r = (ll)1e9, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (calc(mid)) {
            res = max(res, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res;

    return 0;
}