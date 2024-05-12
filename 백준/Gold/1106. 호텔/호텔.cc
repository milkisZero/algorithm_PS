#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 2000

ll dp[2004];

int main() {
    fastio;

    ll c, n;
    cin >> c >> n;
    vector<pll> v(n);
    for (auto &[f, s] : v) cin >> f >> s;

    fill(dp, dp + MAX + 1, INF);

    dp[0] = 0;
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j < n; j++) {
            auto [f, s] = v[j];
            if (i + s <= MAX) dp[i + s] = min(dp[i + s], dp[i] + f);
        }
    }

    ll res = LLINF;
    for (int i = c; i <= MAX; i++) {
        res = min(res, dp[i]);
    }
    cout << res;

    return 0;
}