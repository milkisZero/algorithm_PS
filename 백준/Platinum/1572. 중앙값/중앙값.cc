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

ll find_value(ll n, ll l, ll r, ll val) {
    if (l == r) return l;
    ll m = (l + r) / 2;
    if (sg[2 * n] < val) return find_value(2 * n + 1, m + 1, r, val - sg[2 * n]);
    else return find_value(2 * n, l, m, val);
}

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    ll sum = 0;

    vector<ll> vec(n + 1);
    vec[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        vec[i]++;

        upd(1, 1, MAX, vec[i], 1);

        if (i >= k) {
            upd(1, 1, MAX, vec[i - k], -1);
            sum += find_value(1, 1, MAX, (k + 1) / 2) - 1;
        }
    }

    cout << sum;

    return 0;
}