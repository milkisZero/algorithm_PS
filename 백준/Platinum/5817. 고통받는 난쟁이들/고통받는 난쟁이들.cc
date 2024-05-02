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

ll sg[MAX * 4], arr[MAX], idx[MAX];
pll sg2[MAX * 4];

void init(ll n, ll s, ll e) {
    if (s == e) {
        sg[n] = idx[s];
        return;
    }
    ll m = (s + e) / 2;
    init(2 * n, s, m), init(2 * n + 1, m + 1, e);
    sg[n] = sg[2 * n] + sg[2 * n + 1];
}

void init2(ll n, ll s, ll e) {
    if (s == e) {
        sg2[n] = {idx[s], idx[s]};
        return;
    }
    ll m = (s + e) / 2;
    init2(2 * n, s, m), init2(2 * n + 1, m + 1, e);
    pll a = sg2[2 * n], b = sg2[2 * n + 1];
    sg2[n] = {min(a.first, b.first), max(a.second, b.second)};
}

void upd(ll n, ll s, ll e, ll t, ll val) {
    if (t < s || e < t) return;
    else if (s == e) {
        sg[n] += val;
        return;
    }
    ll m = (s + e) / 2;
    upd(2 * n, s, m, t, val), upd(2 * n + 1, m + 1, e, t, val);
    sg[n] = sg[2 * n] + sg[2 * n + 1];
}

void upd2(ll n, ll s, ll e, ll t, ll val) {
    if (t < s || e < t) return;
    else if (s == e) {
        sg2[n] = {val, val};
        return;
    }
    ll m = (s + e) / 2;
    upd2(2 * n, s, m, t, val), upd2(2 * n + 1, m + 1, e, t, val);
    pll a = sg2[2 * n], b = sg2[2 * n + 1];
    sg2[n] = {min(a.first, b.first), max(a.second, b.second)};
}

ll query_sum(ll n, ll s, ll e, ll l, ll r) {
    if (r < s || e < l) return 0;
    else if (l <= s && e <= r) return sg[n];
    ll m = (s + e) / 2;
    return query_sum(2 * n, s, m, l, r) + query_sum(2 * n + 1, m + 1, e, l, r);
}

pll min_max(ll n, ll s, ll e, ll l, ll r) {
    if (r < s || e < l) return {LLINF, -1};
    else if (l <= s && e <= r) return sg2[n];
    ll m = (s + e) / 2;
    pll a = min_max(2 * n, s, m, l, r), b = min_max(2 * n + 1, m + 1, e, l, r);
    return {min(a.first, b.first), max(a.second, b.second)};
}

int main() {
    fastio;

    ll n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }
    init(1, 1, n);
    init2(1, 1, n);

    while (m--) {
        cin >> a >> b >> c;
        if (a == 1) {
            upd(1, 1, n, arr[b], -idx[arr[b]] + idx[arr[c]]);
            upd(1, 1, n, arr[c], -idx[arr[c]] + idx[arr[b]]);

            upd2(1, 1, n, arr[b], idx[arr[c]]);
            upd2(1, 1, n, arr[c], idx[arr[b]]);

            swap(idx[arr[b]], idx[arr[c]]);
            swap(arr[b], arr[c]);
        }
        else {
            ll k = query_sum(1, 1, n, b, c);
            auto [mini, maxi] = min_max(1, 1, n, b, c);
            if (k == maxi * (maxi + 1) / 2 - mini * (mini - 1) / 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}