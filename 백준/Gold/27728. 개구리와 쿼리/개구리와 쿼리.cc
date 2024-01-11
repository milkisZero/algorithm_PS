#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[505][505];
int sum[505][505];
int dp[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            sum[i][j] = sum[i][j - 1] + arr[i][j];
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            dp[0][i] = INF;
            dp[j][i] = min(dp[j - 1][i], sum[j][n] - sum[j][i - 1]);
        }
    }

    while (q--) {
        int x, y, l;
        cin >> x >> y >> l;

        int res = sum[x][n] - sum[x][y - 1];
        for (int j = y - 1; j <= n - 1; j++) {
            int tmp = sum[x][j] - sum[x][y - 1];
            res = min(res, tmp + dp[x - l][j + 1]);
        }

        cout << res << '\n';
    }

    return 0;
}