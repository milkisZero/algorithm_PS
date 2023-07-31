#include <iostream>
using namespace std;
using ll = long long;

ll fact[2005];

ll nCr(ll fact, ll invFact, ll powN, ll mod) {
    while (powN) {
        if (powN % 2)
            fact = (fact * invFact) % mod;
        powN /= 2;
        invFact = (invFact * invFact) % mod;
    }
    return fact;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll n, k, m;
    cin >> n >> k >> m;

    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= m; i++) {
        fact[i] = (fact[i - 1] * i) % m;
    }

    ll res = 1;
    while (n || k) {
        if (n % m < k % m) {
            res = 0;
            break;
        }
        res *= nCr(fact[n % m], fact[k % m] * fact[(n % m) - (k % m)], m - 2, m) % m;
        res %= m;
        n /= m, k /= m;
    }

    cout << res;

    return 0;
}