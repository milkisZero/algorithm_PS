#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    while (1) {
        int n;
        double tmp;
        cin >> n >> tmp;
        int m = round(tmp * 100);

        if (!n && !m)
            break;

        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i].first;
            cin >> tmp;
            vec[i].second = round(tmp * 100);
        }

        vector<int> dp(m + 1);
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= vec[j].second)
                    dp[i] = max(dp[i - vec[j].second] + vec[j].first, dp[i]);
            }
        }

        cout << dp[m] << '\n';
    }

    return 0;
}