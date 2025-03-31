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

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    ll q;
    cin >> q;
    while (q--) {
        ll x, y, z, k;
        cin >> x >> y >> z >> k;

        ll res = 0, line = 0, idx = 0;
        ll l = min(a[0], min(b[0], c[0])), r = max(a[x - 1], max(b[y - 1], c[z - 1])), m;
        while (l <= r) {
            m = (l + r) / 2;
            ll aidx = lower_bound(a.begin(), a.begin() + x - 1, m) - a.begin();
            ll bidx = lower_bound(b.begin(), b.begin() + y - 1, m) - b.begin();
            ll cidx = lower_bound(c.begin(), c.begin() + z - 1, m) - c.begin();

            if (a[aidx] > m) aidx--;
            if (b[bidx] > m) bidx--;
            if (c[cidx] > m) cidx--;

            if (aidx + bidx + cidx + 3 == k) {
                if (aidx >= 0) {
                    res = a[aidx];
                    line = 1;
                    idx = aidx;
                }
                if (bidx >= 0 && res < b[bidx]) {
                    res = max(res, b[bidx]);
                    line = 2;
                    idx = bidx;
                }
                if (cidx >= 0 && res < c[cidx]) {
                    res = max(res, c[cidx]);
                    line = 3;
                    idx = cidx;
                }

                break;
            }

            if (aidx + bidx + cidx + 3 < k) l = m + 1;
            else r = m - 1;
        }

        cout << line << sp << idx + 1 << endl;
    }

    return 0;
}