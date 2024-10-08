#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 200005

ll seg[(MAX + 5) * 4], arr[MAX + 5];

ll init(ll n, ll l, ll r) {
    if (l == r) return seg[n] = arr[l];
    return seg[n] = init(2 * n, l, (l + r) / 2) + init(2 * n + 1, (l + r) / 2 + 1, r);
}

void upd(ll n, ll l, ll r, ll t, ll val) {
    if (t < l || r < t) return;
    else if (l == r) {
        seg[n] += val;
        return;
    }
    ll m = (l + r) / 2;
    upd(2 * n, l, m, t, val), upd(2 * n + 1, m + 1, r, t, val);
    seg[n] = seg[2 * n] + seg[2 * n + 1];
}

ll qry(ll n, ll l, ll r, ll ql, ll qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[n];
    return qry(2 * n, l, (l + r) / 2, ql, qr) + qry(2 * n + 1, (l + r) / 2 + 1, r, ql, qr);
}

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll maxi = n + m;
        for (int i = 1; i <= n; i++) arr[i] = 1;
        init(1, 1, maxi);

        for (int i = 1; i <= n; i++) arr[i] = n - i + 1;

        ll top = n + 1;
        for (int i = 0; i < m; i++) {
            ll tmp;
            cin >> tmp;

            cout << qry(1, 1, maxi, arr[tmp] + 1, maxi) << ' ';
            upd(1, 1, maxi, arr[tmp], -1);
            arr[tmp] = top++;
            upd(1, 1, maxi, arr[tmp], 1);
        }
        cout << '\n';

        memset(arr, 0, sizeof(arr));
        memset(seg, 0, sizeof(seg));
    }

    return 0;
}