#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<pll> e[10005];
ll d[10005][55];

int main() {
    fastio;

    ll n, m, k, s, t;
    cin >> n >> m >> k;
    cin >> s >> t;

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
    }

    fill(&d[0][0], &d[n + 1][52], LLINF);

    priority_queue<pll> pq;
    pq.push({0, s});
    d[s][0] = 0;

    while (!pq.empty()) {
        auto [q, x] = pq.top();
        pq.pop();
        q = -q;

        if (d[x][q % k] != q) continue;

        for (auto [v, c] : e[x]) {
            ll tmp = q + c;
            if (d[v][tmp % k] > tmp) {
                d[v][tmp % k] = tmp;
                pq.push({-tmp, v});
            }
        }
    }

    if (d[t][0] == LLINF) cout << "IMPOSSIBLE";
    else cout << d[t][0];

    return 0;
}