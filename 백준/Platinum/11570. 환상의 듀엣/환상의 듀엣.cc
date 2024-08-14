#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll dp[2003][2003];

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];

    fill(&dp[0][0], &dp[n + 2][n + 2], LLINF);
    dp[1][0] = dp[0][1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i - 1; j++) {
            ll a = abs(v[i - 1] - v[i]);
            ll b = !j ? 0 : abs(v[j] - v[i]);

            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
            dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + b);

            dp[j][i] = min(dp[j][i], dp[j][i - 1] + a);
            dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][j] + b);
        }
    }

    ll res = LLINF;
    for (int i = 0; i < n; i++) {
        res = min(res, min(dp[n][i], dp[i][n]));
    }
    cout << res;

    return 0;
}