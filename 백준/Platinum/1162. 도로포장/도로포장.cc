// 초반의 큰 수가 포장인 경우에 스킵되서 최종 목적지에 도달하지 않을 수 있다
#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll d[10005][25];
vector<pll> e[10005];

int main() {
    fastio;

    ll n, m, k, a, b, c;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }

    fill(&d[0][0], &d[n + 1][k + 1], LLINF);
    priority_queue<pair<ll, pll>> pq;
    pq.push({0, {1, 0}});
    d[1][0] = 0;

    while (!pq.empty()) {
        ll a = -pq.top().first;
        auto [x, cnt] = pq.top().second;
        pq.pop();
        if (x == n)
            continue;
        if (a == d[x][cnt]) {
            for (auto [u, v] : e[x]) {
                if (cnt + 1 <= k && a < d[u][cnt + 1]) {
                    d[u][cnt + 1] = a;
                    pq.push({-d[u][cnt + 1], {u, cnt + 1}});
                }
                if (a + v < d[u][cnt]) {
                    d[u][cnt] = a + v;
                    pq.push({-d[u][cnt], {u, cnt}});
                }
            }
        }
    }

    ll res = LLINF;
    for (int i = 0; i <= k; i++) {
        res = min(res, d[n][i]);
    }
    cout << res;

    return 0;
}