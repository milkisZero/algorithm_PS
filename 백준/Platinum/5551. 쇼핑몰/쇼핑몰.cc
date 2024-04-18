#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

double d[3005], shop[3005], pre[3005];
vector<pll> e[3005];

int main() {
    fastio;

    ll n, m, k, a, b, l;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> l;
        e[a].push_back({b, l});
        e[b].push_back({a, l});
    }

    fill(d, d + n + 1, LLINF);

    priority_queue<pll> pq;
    for (int i = 0; i < k; i++) {
        cin >> a;
        shop[a] = 1;
        d[a] = 0;
        pq.push({0, a});
    }

    while (!pq.empty()) {
        auto [val, x] = pq.top();
        val = -val;
        pq.pop();
        if (val == d[x]) {
            for (auto [u, v] : e[x]) {
                if (val + v < d[u]) {
                    d[u] = val + v;
                    pre[u] = x;
                    pq.push({-d[u], u});
                }
            }
        }
    }

    double res = 0;
    for (int i = 1; i <= n; i++) {
        if (shop[i]) continue;

        for (auto [u, v] : e[i]) {
            if (pre[i] != u) {
                res = max(res, (d[u] + d[i] + v) / 2.0);
            }
        }
    }

    cout << round(res);

    return 0;
}