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

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<pll> v(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    map<pll, ll> mp;
    for (int i = 0; i < n; i++) {
        auto [a1, a2] = v[i];
        for (int j = i; j < n; j++) {
            ll k = 2;
            if (i == j) k = 1;

            auto [b1, b2] = v[j];
            mp[{(a1 + b1), (a2 + b2)}] += k;
        }
    }

    ll maxi = 0;
    for (auto [p, v] : mp) {
        maxi = max(maxi, v);
    }
    cout << maxi;

    return 0;
}