#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll dp[1024 * 32 + 3][5];

int main() {
    fastio;

    ll maxi = 1024 * 32;
    for (int i = 1; i * i <= maxi; i++) {
        for (int k = i * i; k <= maxi; k++) {
            for (int j = 1; j <= 4; j++) {
                if (k == i * i && j == 1) dp[k][1]++;
                else dp[k][j] += dp[k - i * i][j - 1];
            }
        }
    }

    while (1) {
        ll a;
        cin >> a;
        if (!a) break;

        ll cnt = 0;
        for (int i = 1; i <= 4; i++) cnt += dp[a][i];
        cout << cnt << '\n';
    }

    return 0;
}