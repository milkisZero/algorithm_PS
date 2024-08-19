#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> v(n), dp(n, 1);
    for (auto &e : v) cin >> e;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] < v[j] && dp[j] < dp[i] + 1) dp[j] = dp[i] + 1;
        }
    }

    vector<ll> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (v[i] < v[j] && dp2[j] < dp2[i] + 1) dp2[j] = dp2[i] + 1;
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) res = max(res, dp[i] + dp2[i] - 1);

    cout << res;

    return 0;
}