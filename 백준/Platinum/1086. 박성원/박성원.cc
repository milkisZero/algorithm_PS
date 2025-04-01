#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll dp[1 << 15][100];

int main() {
    fastio;

    ll n, k;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cin >> k;

    ll ten_mod[55], v_mod[n + 5];
    ten_mod[0] = 1 % k;

    for (int i = 1; i <= 50; i++) ten_mod[i] = 10 * ten_mod[i - 1] % k;
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        for (int j = 0; j < v[i].length(); j++) {
            tmp *= 10;
            tmp += (v[i][j] - '0');
            tmp %= k;
        }

        v_mod[i] = tmp % k;
        dp[1 << i][v_mod[i]] = 1;
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;

            for (int m = 0; m < k; m++) {
                ll a = (m * ten_mod[v[j].length()]) + v_mod[j];
                a = a % k;

                dp[i | (1 << j)][a] += dp[i][m];
            }
        }
    }

    ll res = dp[(1 << n) - 1][0];
    if (res == 0) cout << "0/1";
    else {
        ll total = 1;
        for (int i = 1; i <= n; i++) total *= i;
        ll gcdN = gcd(res, total);
        cout << res / gcdN << '/' << total / gcdN;
    }
    return 0;
}