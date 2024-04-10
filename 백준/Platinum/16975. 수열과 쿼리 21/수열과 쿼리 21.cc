#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using ull = unsigned long long;
#define MAX (int)1e6

ll sg[MAX * 4], lz[MAX * 4], a[MAX];
ll l, r;

void init(ll n, ll s, ll e) {
    if (s == e) {
        sg[n] = a[s];
        return;
    }
    ll m = (s + e) / 2;
    init(2 * n, s, m), init(2 * n + 1, m + 1, e);
    sg[n] = sg[2 * n] + sg[2 * n + 1];
}

void propa(ll n, ll s, ll e) {
    if (!lz[n]) return;
    sg[n] += (e - s + 1) * lz[n];
    if (s != e) lz[2 * n] += lz[n], lz[2 * n + 1] += lz[n];
    lz[n] = 0;
}

void upd_range(ll n, ll s, ll e, ll val) {
    propa(n, s, e);
    if (r < s || e < l) return;
    else if (l <= s && e <= r) {
        lz[n] += val, propa(n, s, e);
        return;
    }
    ll m = (s + e) / 2;
    upd_range(2 * n, s, m, val), upd_range(2 * n + 1, m + 1, e, val);
    sg[n] = sg[2 * n] + sg[2 * n + 1];
}

ll query(ll n, ll s, ll e) {
    propa(n, s, e);
    if (r < s || e < l) return 0;
    else if (l <= s && e <= r) return sg[n];
    ll m = (s + e) / 2;
    return query(2 * n, s, m) + query(2 * n + 1, m + 1, e);
}

int main() {
    fastio;
    ll n, m, q, k;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> q;
        if (q == 1) {
            cin >> l >> r >> k;
            upd_range(1, 1, n, k);
        }
        else {
            cin >> k;
            l = r = k;
            cout << query(1, 1, n) << '\n';
        }
    }

    return 0;
}