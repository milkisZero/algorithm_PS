#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll pow(ll r, ll n, ll mod) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return (1 + r) % mod;

    ll res = 1, tmp = n / 2, q = r;
    while (tmp) {
        if (tmp % 2)
            res = (res * q) % mod;
        tmp /= 2;
        q = (q * q) % mod;
    }

    ll k = 0;
    if (n % 2)
        k = (res * res) % mod;
    res = (res + 1) % mod;

    return (k + res * pow(r, n / 2, mod)) % mod;
}

int main() {
    fastio;

    ll a, r, n, mod;
    cin >> a >> r >> n >> mod;

    ll res = (a * pow(r, n, mod)) % mod;
    cout << res;

    return 0;
}