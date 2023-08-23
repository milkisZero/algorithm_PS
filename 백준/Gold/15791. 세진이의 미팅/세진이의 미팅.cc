#include <iostream>
using namespace std;
using ll = long long;
#define MOD 1000000007

ll fact[1000004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll res = fact[n], inFact = (fact[m] * fact[n - m]) % MOD;
    ll powN = MOD - 2;
    while (powN) {
        if (powN % 2)
            res = (res * inFact) % MOD;
        inFact = (inFact * inFact) % MOD;
        powN /= 2;
    }

    cout << res;

    return 0;
}
