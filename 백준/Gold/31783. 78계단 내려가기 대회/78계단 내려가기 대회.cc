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

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> H(n + 1), A(n + 1), B(n + 1);
    vector<ll> H2(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
        H2[n - i + 1] = H[i];
    }
    for (int i = 2; i <= n; i++) cin >> A[i];
    for (int i = 2; i <= n; i++) cin >> B[i];

    vector<ll> dp(n + 1);
    for (int i = n; i > 1; i--) {
        ll idx = lower_bound(H2.begin() + (n - i + 1) + 1, H2.end(), H[i] + B[i]) - H2.begin();
        if (H[i] + B[i] <= H2[idx]) {
            idx = (n + 1) - idx;

            dp[idx] = max(dp[idx], dp[i] + A[i]);
        }

        dp[i - 1] = max(dp[i - 1], dp[i]);
    }

    cout << max(dp[1], dp[2]);

    return 0;
}