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
#define MOD 1000000007

ll dp[10005];

int main() {
    fastio();

    int t;
    cin >> t;

    dp[0] = 1;
    for (ll i = 3; i <= 10000; i += 3) {
        ll q = i / 3;
        dp[i] = (3 * dp[i - 3]) % MOD;
        for (ll j = 2; j <= q; j++) {
            dp[i] += dp[i - j * 3] * 2 * j;
            dp[i] %= MOD;
        }
    }

    while (t--) {
        int n;
        cin >> n;

        if (n % 3)
            cout << 0 << '\n';
        else
            cout << dp[n] << '\n';
    }

    return 0;
}