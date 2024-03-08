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

ll dp[4] = {-INF, -INF, -INF, -INF};

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;

        dp[3] = max(dp[3], dp[2] + tmp);
        dp[2] = max(dp[2], dp[1] - tmp);
        dp[1] = max(dp[1], dp[0] + tmp);
        dp[0] = max(dp[0], -tmp);
    }

    cout << dp[3];

    return 0;
}