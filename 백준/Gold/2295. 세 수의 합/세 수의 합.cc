#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<ll> v, v2;

bool bs(ll k) {
    ll l = 0, r = v2.size() - 1, m;
    while (l <= r) {
        m = (l + r) / 2;

        if (k == v2[m]) return 1;

        if (k > v2[m]) l = m + 1;
        else r = m - 1;
    }

    return 0;
}

int main() {
    fastio;

    ll n;
    cin >> n;
    v.resize(n);
    for (auto &e : v) cin >> e;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v2.push_back(v[i] + v[j]);
        }
    }
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll k = v[i] - v[j];

            if (bs(k)) res = max(res, max(v[i], v[j]));
        }
    }

    cout << res;

    return 0;
}