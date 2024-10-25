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

ll dp[300005][2][2];

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    fill(&dp[1][0][0], &dp[300004][1][1], -INF);

    for (int i = 1; i <= n; i++) {
        // 현재 x, 이전 x
        dp[i][0][0] = max(dp[i - 1][0][0] + v[i], dp[i - 1][0][0] - v[i]);
        // 현재  x, 이전 o
        dp[i][0][1] = max(max(dp[i - 1][1][1] + v[i], dp[i - 1][1][1] - v[i]), max(dp[i - 1][0][1] + v[i], dp[i - 1][0][1] - v[i]));

        // 현재  o, 이전 o
        // 현재  o, 이전 x
        dp[i][1][1] = max(dp[i - 1][0][0] + 2 * v[i], dp[i - 1][1][1] + v[i] * 2);
    }

    cout << max(dp[n][1][1], max(dp[n][0][1], dp[n][0][0]));

    return 0;
}