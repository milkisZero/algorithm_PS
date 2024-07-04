#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (auto &e : v) cin >> e;
    sort(v.begin(), v.end());

    while (k--) {
        ll l, r, x;
        cin >> l >> r >> x;

        l--, r--;
        for (int i = l; i <= r; i++) v[i] += x;
        vector<ll> tmp(n);

        ll idx = 0, idx1 = 0, idx2 = l;
        if (idx1 == l) idx1 = r + 1;

        while (idx1 < n && idx2 < r + 1) {
            if (v[idx1] <= v[idx2]) {
                tmp[idx++] = v[idx1++];
                if (idx1 == l) idx1 = r + 1;
            }
            else {
                tmp[idx++] = v[idx2++];
            }
        }
        if (idx1 == n) {
            while (idx2 < r + 1) tmp[idx++] = v[idx2++];
        }
        else if (idx2 == r + 1) {
            while (idx1 < n) {
                tmp[idx++] = v[idx1++];
                if (idx1 == l) idx1 = r + 1;
            }
        }

        v = tmp;
    }

    for (auto &e : v) cout << e << ' ';

    return 0;
}