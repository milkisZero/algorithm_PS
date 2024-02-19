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

int arr[1003], dp[1003][1003];

int main() {
    fastio;

    int n, m, a, d;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][0] = dp[i - 1][0] + arr[i];
    }
    cin >> a >> d;

    for (int i = d; i <= n; i++) {
        for (int j = 1; j <= i / d + 1; j++) {
            dp[i][j] = max(dp[i - 1][j] + arr[i], dp[i - d][j - 1] + a);

            if (i == n)
                dp[n][j] = max(dp[n][j], dp[n - 1][j - 1] + a);
        }
    }

    for (int j = 0; j <= n / d + 1; j++) {
        if (dp[n][j] >= m) {
            cout << j;
            return 0;
        }
    }

    cout << -1;

    return 0;
}