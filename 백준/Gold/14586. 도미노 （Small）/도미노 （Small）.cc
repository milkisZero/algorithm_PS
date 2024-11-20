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

vector<pll> domi;
ll val[305][3];
ll dp[305];

int main() {
    fastio;

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        domi.push_back({a, b});
    }
    sort(domi.begin(), domi.end());

    for (int i = 0; i < n; i++) {
        ll k = domi[i].first + domi[i].second;
        for (int j = i + 1; j < n; j++) {
            auto [a, b] = domi[j];
            if (a > k) {
                break;
            }
            val[i][1]++;
            k = max(k, a + b);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        ll k = domi[i].first - domi[i].second;
        for (int j = i - 1; j >= 0; j--) {
            auto [a, b] = domi[j];
            if (a < k) {
                break;
            }
            val[i][0]++;
            k = min(k, a - b);
        }
    }

    vector<ll> v[304];
    for (int i = 0; i < n; i++) {
        v[i - val[i][0]].push_back(val[i][0]);
    }

    fill(dp + 1, dp + 304, LLINF);
    ll res = INF;
    for (int i = 0; i < n; i++) {
        if (dp[i] == LLINF) continue;

        if (i + val[i][1] + 1 > n - 1) res = min(res, dp[i] + 1);
        else dp[i + val[i][1] + 1] = min(dp[i + val[i][1] + 1], dp[i] + 1);

        for (auto e : v[i]) {
            if (i + e + 1 > n - 1) res = min(res, dp[i] + 1);
            else dp[i + e + 1] = min(dp[i + e + 1], dp[i] + 1);
        }
    }

    cout << res;

    return 0;
}