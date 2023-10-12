#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

ll d[100005];
vector<pair<ll, ll>> e[100005];
priority_queue<pair<ll, ll>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll k, m, n;
    ll x, y, z;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        e[y].push_back({x, z});
    }

    fill(d + 1, d + n + 1, INF);
    for (int i = 0; i < k; i++) {
        ll tmp;
        cin >> tmp;
        d[tmp] = 0;
        Q.push({0, tmp});
    }

    for (; Q.size();) {
        ll u = Q.top().second;
        x = -Q.top().first;
        Q.pop();
        if (x == d[u]) {
            for (auto &p : e[u]) {
                ll v = p.first;
                if (x + p.second < d[v]) {
                    d[v] = x + p.second;
                    Q.push({-d[v], v});
                }
            }
        }
    }

    ll maxi = -1, idx;
    for (int i = 1; i <= n; i++) {
        if (maxi < d[i]) {
            maxi = max(maxi, d[i]);
            idx = i;
        }
    }

    cout << idx << '\n'
         << maxi;

    return 0;
}