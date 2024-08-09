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

ll seg[MAX * 4], lz[MAX * 4], arr[MAX];

void init(ll n, ll l, ll r) {
    if (l == r) {
        seg[n] = arr[l];
        return;
    }
    ll m = (l + r) / 2;
    init(2 * n, l, m), init(2 * n + 1, m + 1, r);
    seg[n] = seg[2 * n] ^ seg[2 * n + 1];
}

void prop(ll n, ll l, ll r) {
    if (!lz[n]) return;
    if ((r - l + 1) % 2) seg[n] ^= lz[n];
    if (l != r) lz[2 * n] ^= lz[n], lz[2 * n + 1] ^= lz[n];
    lz[n] = 0;
}

void upd_range(ll n, ll l, ll r, ll ql, ll qr, ll v) {
    prop(n, l, r);
    if (qr < l || r < ql) return;
    else if (ql <= l && r <= qr) {
        lz[n] ^= v, prop(n, l, r);
        return;
    }
    ll m = (l + r) / 2;
    upd_range(2 * n, l, m, ql, qr, v), upd_range(2 * n + 1, m + 1, r, ql, qr, v);
    seg[n] = seg[2 * n] ^ seg[2 * n + 1];
}

ll qry(ll n, ll l, ll r, ll ql, ll qr) {
    prop(n, l, r);
    if (qr < l || r < ql) return 0;
    else if (ql <= l && r <= qr) return seg[n];
    ll m = (l + r) / 2;
    return qry(2 * n, l, m, ql, qr) ^ qry(2 * n + 1, m + 1, r, ql, qr);
}

int main() {
    fastio;

    ll n, m;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);

    cin >> m;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        b++, c++;

        if (a == 1) {
            cin >> a;
            upd_range(1, 1, n, b, c, a);
        }
        else cout << qry(1, 1, n, b, c) << '\n';
    }

    return 0;
}