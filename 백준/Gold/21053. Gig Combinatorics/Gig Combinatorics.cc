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
#define MOD ((ll)1e9 + 7)

ll dp[4];

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        if (v[i] == 1) dp[1]++;
        else if (v[i] == 2) dp[2] = (dp[2] + dp[2] + dp[1]) % MOD;
        else dp[3] = (dp[3] + dp[2]) % MOD;
    }

    cout << dp[3];

    return 0;
}