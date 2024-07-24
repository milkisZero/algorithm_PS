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

ll calc(ll a, ll pow) {
    ll N = 1;
    while (pow) {
        if (pow % 2) N = (N * a) % MOD;
        pow /= 2;
        a = (a * a) % MOD;
    }

    return N % MOD;
}

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    ll res = 1, inv = 1;
    ll N = sqrt(n) + 1;
    for (int i = 2; i <= N; i++) {

        if (n % i) continue;

        ll v = 0;
        while (n % i == 0) {
            n /= i;
            v++;
        }

        res = (res * (calc(i, v * m + 1) - 1)) % MOD;
        inv = (inv * (i - 1)) % MOD;
    }

    if (n > 1) {
        res = (res * (calc(n, m + 1) - 1)) % MOD;
        inv = (inv * (n - 1)) % MOD;
    }

    cout << (res * calc(inv, MOD - 2)) % MOD;

    return 0;
}