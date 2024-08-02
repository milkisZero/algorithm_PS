#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll mul(ll p, ll a) {
    ll res = 1, t = p;
    while (t) {
        if (t % 2) res = (res * a) % p;
        t /= 2;
        a = (a * a) % p;
    }
    return res;
}

bool prime(ll a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

int main() {
    fastio;

    while (1) {
        ll p, a;
        cin >> p >> a;
        if (!p && !a) break;

        if (prime(p)) {
            cout << "no\n";
            continue;
        }

        ll k = mul(p, a);
        if (k == a) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}