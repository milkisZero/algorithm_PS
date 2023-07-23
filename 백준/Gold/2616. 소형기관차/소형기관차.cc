#include <iostream>
using namespace std;

int prefix[50005];
// 객차의 종류 / 호실
int dp[4][50005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    int k;
    cin >> k;

    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= n - k; j++) {
            dp[i][j + k] = max(dp[i][j + k - 1], dp[i - 1][j] + prefix[j + k] - prefix[j]);
        }
    }

    cout << dp[3][n];

    return 0;
}