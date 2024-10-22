#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll dp[100005][2];

int main() {
    fastio;

    ll n;
    cin >> n;

    ll val[n + 3];
    val[0] = 0;
    for (int i = 1; i <= n; i++) cin >> val[i];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = dp[i][1] = -10000;
    }

    ll maxi = -10000;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(val[i], dp[i - 1][0] + val[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + val[i]);
        maxi = max(maxi, max(dp[i][0], dp[i][1]));
    }

    cout << maxi;

    return 0;
}