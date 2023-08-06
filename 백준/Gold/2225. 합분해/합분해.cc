#include <iostream>
using namespace std;
#define mod 1000000000;

long long dp[203][203];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        dp[1][i] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int q = 0; q <= j; q++) {
                dp[i + 1][j] += (dp[i][q] * dp[1][j - q]) % mod;
                dp[i + 1][j] %= mod;
            }
        }
    }

    cout << dp[k][n];

    return 0;
}