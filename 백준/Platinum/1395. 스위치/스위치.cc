#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 1000001

ll seg[MAX * 4], lz[MAX * 4];

ll prop(ll n, ll l, ll r, ll v) {
    v += lz[n], lz[n] = 0;
    v = v % 2;
    if (l != r) lz[2 * n] += v, lz[2 * n + 1] += v;
    return seg[n] = abs((r - l + 1) * v - seg[n]);
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

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a) cout << qry(1, 1, n, b, c) << '\n';
        else upd(1, 1, n, b, c, 1);
    }

    return 0;
}