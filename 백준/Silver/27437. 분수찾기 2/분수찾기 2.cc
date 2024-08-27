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

    ll x;
    cin >> x;

    ll l = 1, r = 1e10, m;
    while (l < r) {
        m = (l + r) / 2;
        ll k = m * (m + 1) / 2;
        if (x <= k) r = m;
        else l = m + 1;
    }

    ll tmp = x - (r - 1) * r / 2;
    if (r % 2) cout << r + 1 - tmp << '/' << tmp;
    else cout << tmp << '/' << r + 1 - tmp;

    return 0;
}