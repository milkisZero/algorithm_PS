#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[200005];
ll pref[200005];
ll n, q;

ll calc(ll x, ll l, ll r) {
    ll uco = pref[r] - pref[x];
    ll lco = pref[x - 1] - pref[l - 1];

    return uco - arr[x] * (r - x) + arr[x] * (x - l) - lco;
}

int main() {
    fastio;

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;

        ll a = lower_bound(arr + 1, arr + n, l) - arr;
        ll b = lower_bound(arr + 1, arr + n, r) - arr;

        if (arr[b] > r) b--;

        if (b == a || l == r) {
            cout << 0 << '\n';
            continue;
        }

        cout << max(calc(b, a, b), calc(a, a, b)) - calc((b + a) / 2, a, b) << '\n';
    }

    return 0;
}