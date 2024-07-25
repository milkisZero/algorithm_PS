#include <bits/stdc++.h>
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll win[1003];
ll lose[1003];
ll dp[1003][1003];

int main() {
    fastio;

    ll n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> win[i];
    cin >> m;
    for (int j = 1; j <= m; j++) cin >> lose[j];

    ll k;
    cin >> k;

    fill(&dp[0][0], &dp[1002][1002], -LLINF + 1);

    for (int i = 0; i <= n; i++) {
        if (i == 0) dp[0][0] = 0;
        else dp[i][0] = dp[i - 1][0] + win[i];

        for (int j = 1; j <= m; j++) {
            ll tmp1 = lose[j], tmp2 = lose[j], tmp3 = lose[j];

            if (dp[i][j - 1] % k) {
                ll a = dp[i][j - 1] % k;
                if (a < 0) a += k;
                tmp1 = min(a, lose[j]);
            }

            if ((i > 0) && (dp[i - 1][j - 1] + win[i]) % k) {
                ll a = ((dp[i - 1][j - 1] + win[i]) % k);
                if (a < 0) a += k;
                tmp2 = min(a, lose[j]);
            }
            if ((i > 0) && (dp[i - 1][j - 1]) % k) {
                ll a = (dp[i - 1][j - 1]) % k;
                if (a < 0) a += k;
                tmp3 = min(a, lose[j]);
            }

            dp[i][j] = dp[i][j - 1] - tmp1;
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + win[i] - tmp3);
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - tmp2 + win[i]);
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + win[i]);
        }
    }

    cout << dp[n][m];

    return 0;
}