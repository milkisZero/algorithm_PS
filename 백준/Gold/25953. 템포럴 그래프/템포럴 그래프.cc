#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fio() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
using namespace std;

ll dp[1005][10005];

int main() {
    fio();

    ll n, t, m;
    cin >> n >> t >> m;

    ll s, e;
    cin >> s >> e;

    fill(&dp[0][0], &dp[1004][10004], INT_MAX);

    vector<array<ll, 3>> g[t + 5];
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < m; j++) {
            ll a, b, c;
            cin >> a >> b >> c;
            g[i].push_back({a, b, c});
            g[i].push_back({b, a, c});
        }
    }

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (auto [a, b, c] : g[i]) {
            if (a == s) dp[i][b] = min(dp[i][b], c);
            else dp[i][b] = min(dp[i][b], dp[i - 1][a] + c);
        }
    }

    ll ans = dp[t][e];
    if (ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}