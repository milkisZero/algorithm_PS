#include <iostream>
using namespace std;
using ll = long long;

ll exgcd(ll a, ll b) {
    ll r1 = a, r2 = b;
    ll s1 = 1, s2 = 0;
    ll r, s, q;
    while (r2) {
        q = r1 / r2;

        r = r1 % r2;
        r1 = r2, r2 = r;

        s = s1 - q * s2;
        s1 = s2, s2 = s;
    }
    r = r1, s = s1;

    if (r == 1)
        return s = s < 0 ? s + b : s;
    else
        return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll n, a;
    cin >> n >> a;

    ll invSum = n - a, invMul = exgcd(a, n);
    cout << invSum << ' ' << invMul;

    return 0;
}
