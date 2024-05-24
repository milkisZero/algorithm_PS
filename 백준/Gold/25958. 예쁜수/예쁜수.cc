#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll pret[6005];
ll dp[6005];

int main() {
    fastio;

    ll m, k;
    cin >> m >> k;

    for (int i = 1; i <= m; i++) {
        string s = to_string(i);
        ll q = 0;
        for (int j = 0; j < s.length(); j++) {
            q += (s[j] - '0');
        }

        if (i % q == 0) pret[i] = 1;
    }

    for (int j = 1; j <= m; j++) {
        if (pret[j] == 0) continue;
        dp[j]++;

        for (int i = 1; i <= m; i++) {
            if (i - j > 0) dp[i] += dp[i - j];
            dp[i] %= k;
        }
    }

    cout << dp[m];

    return 0;
}