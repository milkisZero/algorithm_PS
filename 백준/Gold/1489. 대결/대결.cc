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

ll dp[55][55];

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> av(n + 1), bv(n + 1);
    for (int i = 1; i <= n; i++) cin >> av[i];
    for (int i = 1; i <= n; i++) cin >> bv[i];

    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            if (av[i] == bv[k])
                dp[i][k] = max(1ll, dp[i - 1][k]);
            else if (av[i] > bv[k])
                dp[i][k] = max(2ll, dp[i - 1][k]);
        }
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (av[i] == bv[k])
                    dp[i][k] = max(dp[i][k], dp[i - 1][j] + 1);
                else if (av[i] > bv[k])
                    dp[i][k] = max(dp[i][k], dp[i - 1][j] + 2);
            }
        }
    }

    cout << *max_element(dp[n] + 1, dp[n] + n + 1);

    return 0;
}