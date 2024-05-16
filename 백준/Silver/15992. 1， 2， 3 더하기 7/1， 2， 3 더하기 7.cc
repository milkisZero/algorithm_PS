#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000009

ll dp[1005][1005];

int main() {
    fastio;

    ll t;
    cin >> t;

    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    dp[2][2] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    for (int i = 4; i < 1003; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 3][j - 1]) % MOD;
        }
    }

    while (t--) {
        ll n, m;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }

    return 0;
}