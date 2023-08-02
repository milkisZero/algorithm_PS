#include <iostream>
#include <memory.h>
using namespace std;

int dp[505][505];
int arr[505];
int prefix[505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            dp[i][i] = arr[i];
            prefix[i] = prefix[i - 1] + arr[i];
        }

        for (int i = n; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = i; k + 1 <= j; k++) {
                    if (dp[i][j] == 0) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                    else {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
                dp[i][j] += prefix[j] - prefix[i - 1];
            }
        }

        cout << dp[1][n] - prefix[n] << '\n';

        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
    }

    return 0;
}