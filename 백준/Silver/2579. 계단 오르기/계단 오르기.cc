#include <iostream>
using namespace std;

int arr[305];
int dp[305][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            int a = dp[i - 1 - j][0] + arr[i];
            if (j == 0)
                a = -1;

            int b = dp[i - 1 - j][1] + arr[i];
            dp[i][j] = max(a, b);
        }
    }

    cout << max(dp[n][0], dp[n][1]);

    return 0;
}