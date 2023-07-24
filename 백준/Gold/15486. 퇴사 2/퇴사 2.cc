#include <iostream>
using namespace std;

int arr[1500005][2];
int dp[1500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        dp[i + arr[i][0]] = max(dp[i + arr[i][0]], dp[i] + arr[i][1]);
        if (i + arr[i][0] - 1 < n)
            res = max(res, dp[i + arr[i][0]]);
    }

    cout << res;

    return 0;
}