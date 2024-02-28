#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll mul(ll a, ll b, ll mod) {
    ll cur = a, result = 0;
    while (b) {
        if (b % 2 == 1)
            result += cur;
        cur = (cur * 2) % mod;
        b /= 2;
    }
    return result % mod;
}

ll ans(ll n, ll a, ll p) {
    if (p == 0) {
        if (n == 1 || n == 9)
            return n;
        else if (n == 3)
            return 7;
        else if (n == 7)
            return 3;
    }

    for (int i = 0; i < 10; i++) {
        ll k = a + i * (ll)round(pow(10, p));
        ll mod = round(pow(10, p + 1));
        ll q = mul(mul(k, k, mod), k, mod);
        if (q == n)
            return i;
    }
    return 0;
}

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        ll res = 0;
        string n = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            ll idx = (s.length() - 1) - i;
            n = s[i] + n;
            res += ans(stoll(n), res, idx) * (ll)round(pow(10, idx));
        }

        cout << res << '\n';
    }

    return 0;
}