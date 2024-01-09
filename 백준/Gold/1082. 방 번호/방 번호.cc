#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i].first = i;
        cin >> vec[i].second;
    }
    cin >> m;

    vector<int> dp(m + 1);
    dp[0] = 0;
    int res[m + 1][10] = {0};
    for (int i = 0; i <= m; i++) {
        int maxi = 0;
        for (int j = 0; j < n; j++) {
            if (i == m && j == 0)
                continue;

            for (int p = 1; p * vec[j].second <= i; p++) {
                int tmp = i - vec[j].second * p;

                if (dp[i] < dp[tmp] + p) {
                    dp[i] = dp[tmp] + p;

                    for (int k = 0; k < 10; k++) {
                        res[i][k] = res[tmp][k];
                    }
                    res[i][j] += p;
                    maxi = j;
                }
                else if (dp[i] == dp[tmp] + p) {
                    if (vec[maxi].first < vec[j].first) {

                        for (int k = 0; k < 10; k++) {
                            res[i][k] = res[tmp][k];
                        }
                        res[i][j] += p;
                        maxi = j;
                    }
                }
            }
        }
    }

    for (int i = 9; i >= 0; i--) {
        for (int j = 1; j <= res[m][i]; j++) {
            cout << i;
        }
    }

    if (dp[m] == 0)
        cout << 0;

    return 0;
}