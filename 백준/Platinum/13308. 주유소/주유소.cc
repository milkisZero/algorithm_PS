#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll price[2505], d[4005][4005];
vector<pll> e[2505];

// 다익 -> 다시 왓던 곳을 거쳐 갈 수 있다 -> 상태공간을 하나 늘려?
// prev -> 현재에는 큰 값이 나중에 작아지는데 먼저 방문한 작은 경로에 의해 갱신이 안됨

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
    priority_queue<pair<pll, ll>> pq;
    pq.push({{0, 0}, 1});

    ll res = LLINF;
    while (!pq.empty()) {
        auto [val, cost] = pq.top().first;
        val = -val;
        ll x = pq.top().second;
        pq.pop();

        if (d[x][cost] == val) {
            for (auto [u, v] : e[x]) {
                ll tmp = min(cost, price[x]);
                if (!cost)
                    tmp = price[x];
                if (val + v * tmp < d[u][tmp]) {
                    d[u][tmp] = val + v * tmp;
                    pq.push({{-d[u][tmp], tmp}, u});

                    if (u == n)
                        res = min(res, d[n][tmp]);
                }
            }
        }
    }

    cout << res;

    return 0;
}