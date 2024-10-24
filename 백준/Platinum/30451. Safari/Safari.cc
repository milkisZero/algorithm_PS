#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll dp[5005];

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<pair<pll, pll>> point(n + 1);
    for (int i = 1; i < n + 1; i++) {
        ll a, b;
        cin >> a >> b;
        point[i].second = {a, b};
    }
    for (int i = 1; i < n + 1; i++) {
        ll a, b;
        cin >> a >> b;
        point[i].first = {a, b};
    }
    sort(point.begin(), point.end());

    fill(dp + 1, dp + n + 1, -INF);

    for (int i = 0; i < n + 1; i++) {
        auto [t1, p1] = point[i];

        for (int j = i + 1; j < n + 1; j++) {
            auto [t2, p2] = point[j];
            ll val = abs(p1.first - p2.first) + abs(p1.second - p2.second);

            ll time = t1.second + val;
            if (time <= t2.second) {
                dp[j] = max(dp[j], dp[i] + t2.second - max(time, t2.first));
            }
        }
    }

    cout << *max_element(dp, dp + n + 1);

    return 0;
}