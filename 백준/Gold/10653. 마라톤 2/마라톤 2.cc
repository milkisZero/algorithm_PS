#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

pi arr[503];
ll dp[503][503];  
ll dist[503][503];

ll td(ll n, ll k) {
    if (n <= 1) return 0;
    if (dp[n][k] != -1) return dp[n][k];

    ll mini = LLINF;
    for (int i = 0; i <= k; i++) {
        if (1 <= n - i - 1)
            mini = min(mini, td(n - i - 1, k - i) + dist[n - i - 1][n]);
    }
    return dp[n][k] = mini;
}

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    ll a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        arr[i] = {a, b};
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            auto [ix, iy] = arr[i];
            auto [jx, jy] = arr[j];
            dist[i][j] = abs(ix - jx) + abs(iy - jy);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << td(n, k);

    return 0;
}