#include <iostream>
using namespace std;

long long dp[202][202];
long long arr[6][202];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w;
    cin >> h >> w;
    if (h == 0) {
        cout << 1;
        return 0;
    }

    dp[0][1] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 0; j <= w; j++) {
            if (j == 0)
                dp[i][j] = 1;
            else {
                for (int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= 1000000007;
                }
            }
        }
    }

    arr[0][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= w; k++) {
                if (arr[i - 1][k]) {
                    arr[i][j] += arr[i - 1][k] * dp[k][j];
                    arr[i][j] %= 1000000007;
                }
            }
        }
    }

    long long res = 0;
    for (int i = 1; i <= w; i++) {
        res += arr[h][i];
        res %= 1000000007;
    }

    cout << res;

    return 0;
}