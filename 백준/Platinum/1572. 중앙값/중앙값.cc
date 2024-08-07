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

    ll n, k;
    cin >> n >> k;

    ll sum = 0;

    vector<ll> vec(n + 1);
    vec[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        tmp++;

        vec[i] = tmp;

        upd(1, 1, MAX, tmp, 1);

        if (i >= k) {
            upd(1, 1, MAX, vec[i - k], -1);

            ll l = 1, r = MAX, m;
            while (l < r) {
                m = (l + r) / 2;

                ll v = qry(1, 1, MAX, 1, m);

                if (v < (k + 1) / 2) l = m + 1;
                else r = m;
            }

            sum += r - 1;
        }
    }

    cout << sum;

    return 0;
}