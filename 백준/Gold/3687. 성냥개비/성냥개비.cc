#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll dp[106];

int main() {
    fastio;

    fill(dp, dp + 101, LLINF);

    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 0;
    dp[7] = 8;

    for (int i = 8; i <= 100; i++) {
        for (int j = 2; j <= i - 2; j++) {
            string a = to_string(dp[i - j]) + to_string(dp[j]);
            if (dp[i - j] == 0)
                a = "6" + to_string(dp[j]);

            dp[i] = min(dp[i], stoll(a));
        }
    }

    dp[6] = 6;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << dp[n] << ' ';

        int k = n % 2, p = n / 2;
        if (k == 1) {
            k += 2;
            p--;
        }

        while (k /= 3) {
            cout << 7;
        }
        while (p--) {
            cout << 1;
        }
        cout << '\n';
    }

    return 0;
}