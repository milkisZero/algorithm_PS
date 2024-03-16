#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 10000

int dp[10005];

int main() {
    fastio;

    int t;
    cin >> t;

    dp[0] = dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for (int i = 5; i <= MAX; i++) {
        dp[i] = 1 + dp[i - 2] + dp[i - 3] - dp[i - 5];
    }

    int k;
    while (t--) {
        cin >> k;
        cout << dp[k] << '\n';
    }

    return 0;
}