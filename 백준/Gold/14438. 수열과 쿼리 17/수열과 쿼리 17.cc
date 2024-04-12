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

ll sg[MAX * 4], arr[MAX];

void init(ll n, ll s, ll e) {
    if (s == e) {
        sg[n] = arr[s];
        return;
    }
    ll m = (s + e) / 2;
    init(2 * n, s, m), init(2 * n + 1, m + 1, e);
    sg[n] = min(sg[2 * n], sg[2 * n + 1]);
}

void upd(ll n, ll s, ll e, ll t, ll val) {
    if (t < s || e < t) return;
    else if (s == e) {
        sg[n] = val;
        return;
    }
    ll m = (s + e) / 2;
    upd(2 * n, s, m, t, val), upd(2 * n + 1, m + 1, e, t, val);
    sg[n] = min(sg[2 * n], sg[2 * n + 1]);
}

ll query(ll n, ll s, ll e, ll l, ll r) {
    if (r < s || e < l) return LLINF;
    else if (l <= s && e <= r) return sg[n];
    ll m = (s + e) / 2;
    return min(query(2 * n, s, m, l, r), query(2 * n + 1, m + 1, e, l, r));
}
int main() {
    fastio;

    ll n, m, q, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);

    cin >> m;
    while (m--) {
        cin >> q >> a >> b;
        if (q == 1) upd(1, 1, n, a, b);
        else cout << query(1, 1, n, a, b) << '\n';
    }

    return 0;
}