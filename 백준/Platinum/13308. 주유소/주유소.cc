#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll price[2505], d[4005][2505];
vector<pll> e[2505];

int main() {
    fastio;

    ll n, m, a, b, c;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }

    fill(&d[0][0], &d[n + 2][n + 2], LLINF);
    d[1][0] = 0;
    priority_queue<pair<pll, pll>> pq;
    pq.push({{0, INF}, {1, 0}});

    while (!pq.empty()) {
        auto [val, cost] = pq.top().first;
        val = -val;
        auto [x, cnt] = pq.top().second;
        pq.pop();

        if (d[x][cnt] == val) {
            for (auto [u, v] : e[x]) {
                ll tmp = min(cost, price[x]);
                if (val + v * tmp < d[u][cnt + 1] && cnt < n) {
                    d[u][cnt + 1] = val + v * tmp;
                    pq.push({{-d[u][cnt + 1], tmp}, {u, cnt + 1}});
                }
            }
        }
    }

    ll res = LLINF;
    for (int i = 1; i <= n; i++) {
        res = min(res, d[n][i]);
    }

    cout << res;

    return 0;
}