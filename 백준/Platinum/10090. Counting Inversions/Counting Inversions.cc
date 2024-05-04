#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX (int)1e6

ll sg[MAX * 4];

void upd(ll n, ll l, ll r, ll t, ll val) {
    if (t < l || r < t) return;
    else if (l == r) {
        sg[n] += val;
        return;
    }
    ll m = (l + r) / 2;
    upd(2 * n, l, m, t, val), upd(2 * n + 1, m + 1, r, t, val);
    sg[n] = sg[2 * n] + sg[2 * n + 1];
}

ll qry(ll n, ll l, ll r, ll ql, ll qr) {
    if (qr < l || r < ql) return 0;
    else if (ql <= l && r <= qr) return sg[n];
    ll m = (l + r) / 2;
    return qry(2 * n, l, m, ql, qr) + qry(2 * n + 1, m + 1, r, ql, qr);
}

int main() {
    fastio;
    ll n, a, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) upd(1, 1, n, i, 1);

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a > 1) sum += qry(1, 1, n, 1, a - 1);
        upd(1, 1, n, a, -1);
    }
    cout << sum;

    return 0;
}