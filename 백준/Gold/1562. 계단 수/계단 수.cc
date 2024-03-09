#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <map>
#include <math.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define mod 1000000000

ll dp[103][13][1 << 10];

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < (1 << 10); k++) {
                if (j == 0)
                    dp[i][j][(k | (1 << j))] += dp[i - 1][j + 1][k];
                else if (j == 9)
                    dp[i][j][(k | (1 << j))] += dp[i - 1][j - 1][k];
                else
                    dp[i][j][(k | (1 << j))] += (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % mod;
                dp[i][j][(k | (1 << j))] %= mod;
            }
        }
    }

    ll res = 0;
    for (int k = 0; k < (1 << 10); k++) {
        for (int j = 0; j <= 9; j++) {
            if (k == (1 << 10) - 1) {
                res += dp[n][j][k];
                res %= mod;
            }
        }
    }

    cout << res;

    return 0;
}