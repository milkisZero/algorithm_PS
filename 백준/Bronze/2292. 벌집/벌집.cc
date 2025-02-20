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

    ll x;
    cin >> x;

    ll l = 0, r = 1e5, m;
    ll res = 0;
    while (l <= r) {
        m = (l + r) / 2;
        if (m * m * 3 - 3 * m + 1 < x) {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    cout << res + 1;

    return 0;
}