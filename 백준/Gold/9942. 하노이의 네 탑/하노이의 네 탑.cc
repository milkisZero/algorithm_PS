#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll T(ll n, ll r) {
    if (n == 1)
        return 1;
    if (r == 3)
        return T(n - 1, 3) * 2 + 1;

    ll k = n + 1 - round(sqrt(2 * n + 1));
    return  2 * T(k, r) + T(n - k, r - 1);
}

int main() {
    fastio();

    string s;
    for (int i = 1; getline(cin, s); i++) {
        ll n = stoi(s);
        cout << "Case " << i << ": " << T(n, 4) << '\n';
    }

    return 0;
}