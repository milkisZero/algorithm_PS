#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 10007

ll dp[1003][12];

int main() {
    fastio;

    ll n;
    cin >> n;

    for (int j = 0; j < 10; j++) dp[1][j]++;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k] % MOD;
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < 10; i++) {
        res += dp[n][i];
        res %= MOD;
    }
    cout << res;

    return 0;
}