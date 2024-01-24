#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000009;

map<ll, ll> m;

ll nHr(ll n, ll r) {
    n = n - 1 + r;
    if (n == r)
        return 1;

    ll fact = 1;
    for (ll i = n - r + 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }

    ll invFact = 1;
    for (ll i = 1; i <= r; i++) {
        invFact = (invFact * i) % MOD;
    }

    ll powN = 1000000009 - 2;
    while (powN) {
        if (powN % 2)
            fact = (fact * invFact) % MOD;
        powN /= 2;
        invFact = (invFact * invFact) % MOD;
    }

    return fact;
}

int main() {
    fastio();

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll input, num = 2;
        cin >> input;

        ll tmp = input;
        while (tmp > 1) {
            if (sqrt(input) < num) {
                if (m.find(tmp) == m.end())
                    m.insert({tmp, 1});
                else
                    m[tmp]++;
                break;
            }

            if (tmp % num == 0) {
                if (m.find(num) == m.end())
                    m.insert({num, 1});
                else
                    m[num]++;
                tmp /= num;
            }
            else
                num++;
        }
    }

    ll res = 1;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        res *= nHr(n, iter->second) % MOD;
        res %= MOD;
    }

    cout << res << '\n';

    return 0;
}