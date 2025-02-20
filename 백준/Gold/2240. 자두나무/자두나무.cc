// #dp
// 인덱싱에 주의
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

ll dp[35][5];

int main() {
    fastio;

    ll t, w;
    cin >> t >> w;

    fill(&dp[0][0], &dp[34][4], -INF);
    dp[0][1] = 0;

    for (int i = 1; i <= t; i++) {
        ll cur;
        cin >> cur;

        for (int j = 0; j <= w; j++) {
            if (j == 0) {
                if (cur == 1) dp[j][1] += 1;
                else dp[j][2] += 1;
            }
            else {
                if (cur == 1) dp[j][1] = max(dp[j][1] + 1, dp[j - 1][2] + 1);
                else dp[j][2] = max(dp[j][2] + 1, dp[j - 1][1] + 1);
            }
        }
    }

    ll res = 0;
    for (int j = 0; j <= w; j++) {
        res = max(res, max(dp[j][1], dp[j][2]));
    }
    cout << res;

    return 0;
}