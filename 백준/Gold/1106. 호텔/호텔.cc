#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll dp[2003];

int main() {
    fastio;

    ll c, n;
    cin >> c >> n;
    vector<pll> v(n);
    for (auto &[f, s] : v) cin >> f >> s;

    fill(dp, dp + c + 101, INF);

    dp[0] = 0;
    for (int i = 0; i <= 100 + c; i++) {
        for (int j = 0; j < n; j++) {
            auto [f, s] = v[j];
            if (i + s <= 100 + c) dp[i + s] = min(dp[i + s], dp[i] + f);
        }
    }

    ll res = LLINF;
    for (int i = c; i <= 100 + c; i++) {
        res = min(res, dp[i]);
    }
    cout << res;

    return 0;
}