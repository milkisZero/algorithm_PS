#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll n;
    cin >> n;
    vector<pair<pll, ll>> v(n);
    ll idx = 1;
    for (auto &[a, b] : v) {
        cin >> a.first >> a.second;
        b = idx++;
    }

    sort(v.begin(), v.end(), [](pair<pll, ll> a, pair<pll, ll> b) {
        auto [ap, an] = a;
        auto [bp, bn] = b;
        auto [at, as] = ap;
        auto [bt, bs] = bp;
        if (at * bs == bt * as) return an < bn;
        return at * bs < bt * as;
    });

    for (auto &[a, b] : v) {
        cout << b << ' ';
    }

    return 0;
}