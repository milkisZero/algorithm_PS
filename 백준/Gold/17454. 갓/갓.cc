#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll t;
    cin >> t;
    while (t--) {
        ll dh, ds, hd, hs, sd, sh;
        cin >> dh >> ds >> hd >> hs >> sd >> sh;

        if ((sd * hd) - (sh - sd) * (hs - hd) > 0)
            cout << "GOD\n";
        else
            cout << "KDH\n";
    }

    return 0;
}