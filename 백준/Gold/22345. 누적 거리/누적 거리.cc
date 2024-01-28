#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

pll arr[200005];
ll pref[200005], pref2[200005], pref3[200005];

int cmp(pll a, pll b) {
    return a.second < b.second;
}

int main() {
    fastio();

    ll n, Q;
    cin >> n >> Q;

    for (ll i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr + 1, arr + n + 1, cmp);

    pref[0] = 0, pref2[0] = 0;
    for (ll i = 1; i <= n; i++) {
        pref[i] += pref[i - 1] + arr[i].first * arr[i].second;
        pref2[i] += pref2[i - 1] + arr[i].first;
        pref3[i] = arr[i].second;
    }

    for (ll i = 1; i <= Q; i++) {
        ll q, res;
        cin >> q;

        int lo = lower_bound(pref3 + 1, pref3 + n + 1, q) - pref3;
        int up = upper_bound(pref3 + 1, pref3 + n + 1, q) - pref3;

        res = -pref[lo - 1] + pref2[lo - 1] * q + (pref[n] - pref[up - 1]) - (pref2[n] - pref2[up - 1]) * q;
        cout << res << '\n';
    }

    return 0;
}