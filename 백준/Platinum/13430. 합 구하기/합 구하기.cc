#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MOD 1000000007

int main() {
    fastio;

    ll k, n;
    cin >> k >> n;

    ll fact = 1;
    for (int i = n; i <= n + k; i++)
        fact = (fact * i) % MOD;

    ll inv = 1;
    for (int i = 1; i <= k + 1; i++)
        inv = (inv * i) % MOD;

    ll powN = MOD - 2;
    while (powN) {
        if (powN % 2)
            fact = (fact * inv) % MOD;
        powN /= 2;
        inv = (inv * inv) % MOD;
    }

    cout << fact;

    return 0;
}