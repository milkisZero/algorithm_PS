#include <iostream>
using namespace std;

int arr[1003];
int dp[1003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    int maxN = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j] && dp[j] < dp[i] + 1)
                dp[j] = dp[i] + 1;

            if (maxN < dp[j])
                maxN = dp[j];
        }
    }

    cout << maxN;

    return 0;
}