#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll dp[1003][5];

ll T(ll n, ll r) {
    if (n == 1)
        return 1;
    if (r == 3) {
        if (!dp[n - 1][3])
            dp[n - 1][3] = T(n - 1, 3);
        return dp[n][3] = dp[n - 1][3] * 2 + 1;
    }

    ll k = n + 1 - round(sqrt(2 * n + 1));
    if (!dp[k][4])
        dp[k][4] = T(k, 4);
    if (!dp[n - k][3])
        dp[n - k][3] = T(n - k, 3);

    return dp[k][4] * 2 + dp[n - k][3];
}

int main() {
    fastio();

    dp[1][4] = dp[1][3] = 1;
    string s;
    for (ll i = 1; getline(cin, s); i++) {
        ll n = stoi(s);
        if (!dp[n][4])
            dp[n][4] = T(n, 4);
        cout << "Case " << i << ": " << dp[n][4] << '\n';
    }

    return 0;
}