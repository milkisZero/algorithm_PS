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

    double a, b;
    cin >> a >> b;
    ll c = (b * 100 / a);

    ll l = 0, r = a, m;
    ll res = -1;
    while (l <= r) {
        m = (l + r) / 2;

        ll k = ((b + m) * 100 / (a + m));

        if (k <= c) l = m + 1;
        else {
            r = m - 1;
            res = m;
        }
    }

    cout << res;

    return 0;
}