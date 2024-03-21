#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 100005

pi add[5] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pi arr[MAX], idx[MAX][5];
ll dp[MAX][5];

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    fill(&dp[1][0], &dp[n + 1][5], LLINF);

    for (int i = 0; i < 5; i++) {
        idx[0][i] = arr[0];
    }

    ll res = LLINF;
    for (int i = 1; i <= n; i++) {
        auto [p, q] = arr[i];
        for (int k = 0; k < 5; k++) {
            int c, d;
            auto [a, b] = add[k];
            for (int j = 0; j < 5; j++) {
                auto [x, y] = idx[i - 1][j];
                if (dp[i][k] > dp[i - 1][j] + abs(p + a - x) + abs(q + b - y)) {
                    dp[i][k] = dp[i - 1][j] + abs(p + a - x) + abs(q + b - y);
                    c = p + a, d = q + b;
                }
            }
            idx[i][k] = {c, d};

            if (i == n)
                res = min(res, dp[i][k]);
        }
    }

    cout << res;

    return 0;
}