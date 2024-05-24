#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MOD (ll)(1e9) + 7

ll dp[3002][3002];

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    vector<pll> v(n + 1);
    v[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        auto &[a, b] = v[i];
        cin >> a >> b;
    }

    auto [a, b] = v[1];
    for (int j = a; j <= b; j++) {
        dp[1][j] += dp[1][j - 1] + 1;
    }

    for (int i = 2; i <= n; i++) {
        auto [a, b] = v[i];

        for (int j = a; j <= b; j++) {
            ll e = j + k, s = j - k;

            auto [c, d] = v[i - 1];
            if (s < c) s = c;
            if (e > d) e = d;

            ll tmp = (dp[i - 1][e] - dp[i - 1][s - 1]);
            if (tmp < 0) tmp += MOD;

            dp[i][j] = dp[i][j - 1] + tmp;
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][v[n].second];

    return 0;
}