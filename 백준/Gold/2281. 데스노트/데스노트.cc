#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll arr[1003];
ll dp[1003][1003];

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    fill(&dp[0][0], &dp[1002][1002], LLINF);
    int i;
    for (i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            ll sum = 0;
            for (int k = j + 1; k <= n; k++) {
                sum += arr[k];

                if (sum > m)
                    break;

                ll val = (m - sum) * (m - sum);
                if (i == 1)
                    dp[i][k] = val;
                else
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + val);
                sum++;
            }
            if (i == 1)
                break;
        }
        if (dp[i][n] != LLINF)
            break;
    }

    ll res = LLINF;
    for (int j = 1; j <= n; j++) {
        res = min(res, dp[i - 1][j]);
    }

    if (res == LLINF)
        res = 0;
    cout << res;

    return 0;
}