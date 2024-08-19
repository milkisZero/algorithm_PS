#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX (ll)1e6

ll seg[(MAX + 5) * 4];

ll upd(ll n, ll l, ll r, ll t, ll v) {
    if (t < l || r < t) return seg[n];
    if (l == r) return seg[n] += v;
    return seg[n] = upd(2 * n, l, (l + r) / 2, t, v) + upd(2 * n + 1, (l + r) / 2 + 1, r, t, v);
}

ll find_value(ll n, ll l, ll r, ll v) {
    if (l == r) return l;
    if (seg[2 * n] < v) return find_value(2 * n + 1, (l + r) / 2 + 1, r, v - seg[2 * n]);
    return find_value(2 * n, l, (l + r) / 2, v);
}

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll a, b, c;
        cin >> a >> b;

        if (a == 1) {
            ll k = find_value(1, 1, MAX, b);
            cout << k << '\n';
            upd(1, 1, MAX, k, -1);
        }
        else {
            cin >> c;
            upd(1, 1, MAX, b, c);
        }
    }

    return 0;
}