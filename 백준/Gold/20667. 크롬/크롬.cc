#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll dp[1003][503];
ll arr[103][5];

int main() {
    fastio;

    ll n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    fill(&dp[0][0], &dp[1001][501], -INF);
    dp[0][0] = 0;

    ll res = LLINF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1001; j >= 0; j--) {
            for (ll p = 500; p >= 0; p--) {
                if (dp[j][p] < 0 || p + arr[i][2] > 500) continue;

                if (j + arr[i][0] > 1000) {
                    dp[1001][p + arr[i][2]] = max(dp[j][p] + arr[i][1], dp[1001][p + arr[i][2]]);
                }
                else {
                    dp[j + arr[i][0]][p + arr[i][2]] = max(dp[j][p] + arr[i][1], dp[j + arr[i][0]][p + arr[i][2]]);
                }
            }
        }
    }

    for (int j = m; j <= 1001; j++) {
        for (ll p = 0; p <= 500; p++) {
            if (dp[j][p] >= k) {
                res = min(res, p);
            }
        }
    }

    if (res == LLINF) cout << -1;
    else cout << res;

    return 0;
}