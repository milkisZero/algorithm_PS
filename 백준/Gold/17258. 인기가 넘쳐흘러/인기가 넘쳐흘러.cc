#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll dp[305][305][305];
ll arr[305];

int main() {
    fastio;

    ll n, m, k, t;
    cin >> n >> m >> k >> t;

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++) {
            arr[j]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int q = 0; q <= k; q++) {
            for (int l = 0; l <= q; l++) {

                if (arr[i] >= t) {
                    dp[i][q][0] = max(dp[i][q][0], dp[i - 1][q][l] + 1);
                }
                else {
                    dp[i][q][l] = max(dp[i - 1][q - l][0], dp[i - 1][q][l]);
                    dp[i][q][l] += (arr[i] + l >= t);
                }
            }
        }
    }

    ll res = 0;
    for (int j = 0; j <= k; j++) {
        res = max(res, dp[n][k][j]);
    }

    cout << res;

    return 0;
}