#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 100005

ll seg[(MAX + 5) * 4], arr[MAX + 5];

ll init(ll n, ll l, ll r) {
    if (l == r) return seg[n] = arr[l];
    return seg[n] = init(2 * n, l, (l + r) / 2) * init(2 * n + 1, (l + r) / 2 + 1, r);
}

ll upd(ll n, ll l, ll r, ll t, ll v) {
    if (t < l || r < t) return seg[n];
    if (l == r) return seg[n] = v;
    return seg[n] = upd(2 * n, l, (l + r) / 2, t, v) * upd(2 * n + 1, (l + r) / 2 + 1, r, t, v);
}

ll qry(ll n, ll l, ll r, ll ql, ll qr) {
    if (qr < l || r < ql) return 1;
    if (ql <= l && r <= qr) return seg[n];
    return qry(2 * n, l, (l + r) / 2, ql, qr) * qry(2 * n + 1, (l + r) / 2 + 1, r, ql, qr);
}
int main() {
    fastio;

    ll n, k;
    while (cin >> n >> k) {
        memset(arr, 1, sizeof(arr));
        memset(seg, 1, sizeof(seg));

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] > 0) arr[i] = 1;
            else if (arr[i] < 0) arr[i] = -1;
        }

        init(1, 1, MAX);

        while (k--) {
            char op;
            ll a, b;
            cin >> op >> a >> b;

            if (op == 'C') {
                if (b > 0) b = 1;
                else if (b < 0) b = -1;
                upd(1, 1, MAX, a, b);
            }
            else {
                ll res = qry(1, 1, MAX, a, b);
                if (res > 0) cout << '+';
                else if (res < 0) cout << '-';
                else cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}