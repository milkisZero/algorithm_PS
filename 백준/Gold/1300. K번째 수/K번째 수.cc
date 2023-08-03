#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll bs(ll n, ll k) {
    ll l = 1, r = n * n, m;
    while (l <= r) {
        m = (l + r) / 2;

        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cnt += min(m / i, n);
        }

        if (k > cnt)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    cout << bs(n, k);

    return 0;
}