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

pi arr[103];
int dp[103][5003];
int visited[103][5003];

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    dp[1][1] = 1;
    visited[1][1] = 1;
    for (int i = 2; i <= k; i++) {
        for (int p = 1; p <= 5000; p++) {
            if (visited[i - 1][p]) {
                dp[i][p] = max(dp[i][p], dp[i - 1][p] + p);
                visited[i][p] = 1;
            }
            for (int j = 0; j < n; j++) {
                if (p - arr[j].second > 0 && visited[i - 1][p - arr[j].second] && dp[i - 1][p - arr[j].second] >= arr[j].first) {
                    dp[i][p] = max(dp[i][p], dp[i - 1][p - arr[j].second] - arr[j].first);
                    visited[i][p] = 1;
                }
            }
        }
    }

    int res = 0;
    for (int p = 1; p <= 5000; p++) {
        if (visited[k][p])
            res = max(res, dp[k][p]);
    }

    cout << res;

    return 0;
}