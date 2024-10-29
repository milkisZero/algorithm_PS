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

ll dp[5005][102];

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<ll> v(m);
        for (int i = 0; i < m; i++) cin >> v[i];

        fill(&dp[0][0], &dp[5001][100], -1);
        dp[0][0] = 0;

        for (int j = 0; j <= 100; j++) {
            for (int i = 0; i <= n; i++) {
                if (dp[i][j] == -1) continue;

                for (auto e : v) {
                    if (i + e * (j + 1) <= 5000)
                        dp[i + e * (j + 1)][j + 1] = max(dp[i + e * (j + 1)][j + 1], dp[i][j] + e);

                    // if (i + dp[i][j] + e <= 5000)
                    //  dp[i + dp[i][j] + e][j + 1] = max(dp[i + dp[i][j] + e][j + 1], dp[i][j] + e);
                }
            }
        }

        cout << *max_element(dp[n], dp[n] + 100) << endl;
    }

    return 0;
}