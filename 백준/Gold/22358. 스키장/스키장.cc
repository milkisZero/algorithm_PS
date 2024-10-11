#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<pll> v[100004];
ll dp[11][100005];

int main() {
    fastio;

    ll n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    dp[0][s] = 0;
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            for (auto [a, b] : v[i]) {
                if (dp[j - 1][i] > -1) dp[j - 1][a] = max(dp[j - 1][a], dp[j - 1][i] + b);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto [a, b] : v[i]) {
                dp[j][i] = max(dp[j][i], dp[j - 1][a]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto [a, b] : v[i]) {
            if (dp[k][i] > -1) dp[k][a] = max(dp[k][a], dp[k][i] + b);
        }
    }

    cout << dp[k][t];

    return 0;
}