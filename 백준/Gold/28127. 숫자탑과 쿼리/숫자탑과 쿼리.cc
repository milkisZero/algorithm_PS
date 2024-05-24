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

    ll q;
    cin >> q;

    while (q--) {
        ll a, d, x;
        cin >> a >> d >> x;

        ll A = d, B = 2 * a - d, C = -2 * x;
        double k = (-B + sqrt(B * B - 4 * C * A)) / (2 * A);

        ll tmp;
        tmp = ceil(k);

        ll k2 = tmp - 1;
        k2 = k2 * a + k2 * (k2 - 1) * d / 2;

        cout << tmp << ' ' << x - k2 << '\n';
    }

    return 0;
}