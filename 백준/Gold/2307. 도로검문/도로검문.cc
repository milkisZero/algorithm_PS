#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll d[1003], pre[1003];
vector<pll> edge[1003];
vector<pll> info;

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    fill(d + 2, d + n + 1, LLINF);

    priority_queue<pll> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll x = -pq.top().first;
        pq.pop();

        if (x == d[u]) {
            for (auto e : edge[u]) {
                ll v = e.first;
                if (x + e.second < d[v]) {
                    pre[v] = u;
                    d[v] = x + e.second;
                    pq.push({-d[v], v});
                }
            }
        }
    }

    ll cur = n;
    while (cur != 1) {
        info.push_back({cur, pre[cur]});
        cur = pre[cur];
    }

    ll res = d[n], maxi = -1;

    for (int i = 0; i < info.size(); i++) {
        fill(d + 2, d + n + 1, LLINF);
        pq.push({0, 1});

        while (!pq.empty()) {
            ll u = pq.top().second;
            ll x = -pq.top().first;
            pq.pop();

            if (x == d[u]) {
                for (auto e : edge[u]) {
                    ll v = e.first;
                    if ((info[i].first == u && info[i].second == v) || (info[i].first == v && info[i].second == u))
                        continue;
                    if (x + e.second < d[v]) {
                        d[v] = x + e.second;
                        pq.push({-d[v], v});
                    }
                }
            }
        }
        maxi = max(maxi, d[n]);
    }

    if (maxi == res)
        cout << 0;
    else if (maxi == LLINF)
        cout << -1;
    else
        cout << maxi - res;

    return 0;
}