#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int arr[305][25];
int dp[305][25];

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            for (int p = i; p >= 1; p--) {
                if (dp[i][0] < dp[i - p][0] + arr[p][j]) {
                    for (int k = 1; k <= m; k++) {
                        dp[i][k] = dp[i - p][k];
                    }
                    dp[i][0] = dp[i - p][0] + arr[p][j];
                    dp[i][j] = p;
                }
            }
        }
    }

    cout << dp[n][0] << '\n';
    for (int k = 1; k <= m; k++) {
        cout << dp[n][k] << ' ';
    }

    return 0;
}