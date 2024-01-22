#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll memo[105];
ll cost[105];

int main() {
    fastio();

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> memo[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    ll dp[sum + 1] = {0};
    for (int j = 0; j < n; j++) {
        for (int i = sum; i >= 0; i--) {
            if (i >= cost[j]) {
                dp[i] = max(dp[i], dp[i - cost[j]] + memo[j]);
            }
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (dp[i] >= m) {
            cout << i;
            break;
        }
    }

    return 0;
}