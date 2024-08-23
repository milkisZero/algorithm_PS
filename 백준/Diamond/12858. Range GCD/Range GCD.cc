#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX (ll)1e5

ll seg[(MAX + 5) * 4], arr[MAX + 5];
ll seg2[(MAX + 5) * 4], arr2[MAX + 5];
ll lz[MAX * 4];

ll init(ll n, ll l, ll r) {
    if (l == r) return seg[n] = arr[l];
    return seg[n] = init(2 * n, l, (l + r) / 2) + init(2 * n + 1, (l + r) / 2 + 1, r);
}

ll prop(ll n, ll l, ll r, ll v) {
    v += lz[n], lz[n] = 0;
    if (l != r) lz[2 * n] += v, lz[2 * n + 1] += v;
    return seg[n] += (r - l + 1) * v;
}

ll upd(ll n, ll l, ll r, ll ql, ll qr, ll v) {
    prop(n, l, r, 0);
    if (qr < l || r < ql) return seg[n];
    if (ql <= l && r <= qr) return prop(n, l, r, v);
    return seg[n] = upd(2 * n, l, (l + r) / 2, ql, qr, v) + upd(2 * n + 1, (l + r) / 2 + 1, r, ql, qr, v);
}

ll qry(ll n, ll l, ll r, ll ql, ll qr) {
    prop(n, l, r, 0);
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[n];
    return qry(2 * n, l, (l + r) / 2, ql, qr) + qry(2 * n + 1, (l + r) / 2 + 1, r, ql, qr);
}

ll init2(ll n, ll l, ll r) {
    if (l == r) return seg2[n] = arr2[l];
    return seg2[n] = gcd(init2(2 * n, l, (l + r) / 2), init2(2 * n + 1, (l + r) / 2 + 1, r));
}

ll upd2(ll n, ll l, ll r, ll ql, ll qr, ll v) {
    if (qr < l || r < ql) return seg2[n];
    if (ql <= l && r <= qr && l == r) return seg2[n] += v;
    return seg2[n] = gcd(upd2(2 * n, l, (l + r) / 2, ql, qr, v), upd2(2 * n + 1, (l + r) / 2 + 1, r, ql, qr, v));
}

ll qry2(ll n, ll l, ll r, ll ql, ll qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg2[n];
    return gcd(qry2(2 * n, l, (l + r) / 2, ql, qr), qry2(2 * n + 1, (l + r) / 2 + 1, r, ql, qr));
}

int main() {
    fastio;

    ll n, q;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);

    arr2[1] = arr[1];
    for (int i = 2; i <= n; i++) arr2[i] = abs(arr[i] - arr[i - 1]);
    init2(1, 1, n);

    cin >> q;
    while (q--) {
        ll t, a, b;
        cin >> t >> a >> b;

        if (t) {
            upd(1, 1, n, a, b, t);

            ll k = abs(qry(1, 1, n, a, a) - qry(1, 1, n, a - 1, a - 1)) - qry2(1, 1, n, a, a);
            upd2(1, 1, n, a, a, k);

            k = abs(qry(1, 1, n, b + 1, b + 1) - qry(1, 1, n, b, b)) - qry2(1, 1, n, b + 1, b + 1);
            upd2(1, 1, n, b + 1, b + 1, k);
        }
        else {
            cout << gcd(qry(1, 1, n, a, a), qry2(1, 1, n, a + 1, b)) << '\n';
        }
    }
    return 0;
}