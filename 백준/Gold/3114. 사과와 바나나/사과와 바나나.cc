#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll asum[1505][1505], bsum[1505][1505];
ll dp[1505][1505];

int main() {
    fastio;

    ll r, c;
    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            string s;
            ll acur = 0, bcur = 0;
            cin >> s;

            string k = s;
            k.erase(0, 1);

            if (s[0] == 'A') acur = stoll(k);
            else bcur = stoll(k);
            asum[i][j] = asum[i][j - 1] + acur;
            bsum[i][j] = bsum[i][j - 1] + bcur;
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            ll tmp1 = dp[i - 1][j] + asum[i][j - 1] + bsum[i][c] - bsum[i][j];
            ll tmp2 = dp[i][j - 1] - (bsum[i][j] - bsum[i][j - 1]);
            ll tmp3 = dp[i - 1][j - 1] + asum[i][j - 1] + bsum[i][c] - bsum[i][j];

            if (j == 1) dp[i][j] = tmp1;
            else if (i == 1) dp[i][j] = tmp2;
            else dp[i][j] = max(tmp1, max(tmp2, tmp3));
        }
    }

    cout << dp[r][c];

    return 0;
}