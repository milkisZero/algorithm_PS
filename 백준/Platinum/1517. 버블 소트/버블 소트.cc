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

// 입력과 정렬된 배열을 비교

ll sg[MAX * 4];
ll arr[MAX], arr2[MAX];

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

    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    sort(arr + 1, arr + n + 1);

    map<ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        mp[arr[i]] = i;
    }

    reverse(arr2 + 1, arr2 + 1 + n);

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ll k = mp[arr2[i]];
        upd(1, 1, n, k, 1);
        sum += qry(1, 1, n, 1, k - 1);
    }
    cout << sum;

    return 0;
}