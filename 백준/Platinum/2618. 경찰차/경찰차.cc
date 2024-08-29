#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using ppll = pair<pll, pll>;

ll dp[1003][1003];

int main() {
    fastio;

    ll n, q;
    cin >> n >> q;

    vector<pll> v(q + 1);
    for (int i = 1; i <= q; i++) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    fill(&dp[0][0], &dp[q + 1][q + 1], LLINF);
    dp[0][0] = 0;

    for (int i = 1; i <= q; i++) {
        auto [a, b] = v[i];

        if (i == 1) {
            ll dist = abs(a - 1) + abs(b - 1);
            dp[i][0] = dp[i - 1][0] + dist;
            dist = abs(a - n) + abs(b - n);
            dp[0][i] = dp[0][i - 1] + dist;
        }

        for (int j = 0; j < i - 1; j++) {
            ll dist = abs(a - v[i - 1].first) + abs(b - v[i - 1].second);
            if (i - 1 == 0) dist = abs(a - 1) + abs(b - 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist);

            if (i - 1 == 0) dist = abs(a - n) + abs(b - n);
            dp[j][i] = min(dp[j][i], dp[j][i - 1] + dist);

            dist = abs(a - v[j].first) + abs(b - v[j].second);
            if (j == 0) dist = abs(a - n) + abs(b - n);
            dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][j] + dist);

            if (j == 0) dist = abs(a - 1) + abs(b - 1);
            dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + dist);
        }
    }

    ll res = LLINF;
    ll r1, r2;
    for (int i = 0; i < q; i++) {
        if (res > dp[q][i]) {
            res = dp[q][i];
            r1 = q, r2 = i;
        }
        if (res > dp[i][q]) {
            res = dp[i][q];
            r1 = i, r2 = q;
        }
    }

    vector<ll> vec;
    for (int i = q; i >= 1; i--) {
        if (r1 == i) {
            vec.push_back(1);
            for (int j = i - 1; j >= 1; j--) {
                if (r2 == j) continue;
                ll dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
                if (dp[r1][r2] == dp[j][r2] + dist) {
                    r1 = j;
                    break;
                }
            }
            if (r1 == i) r1 = 0;
        }
        else if (r2 == i) {
            vec.push_back(2);
            for (int j = i - 1; j >= 1; j--) {
                if (r1 == j) continue;
                ll dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
                if (dp[r1][r2] == dp[r1][j] + dist) {
                    r2 = j;
                    break;
                }
            }
            if (r2 == i) r2 = 0;
        }
    }

    cout << res << '\n';
    for (int i = vec.size() - 1; i >= 0; i--) cout << vec[i] << '\n';

    return 0;
}