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

    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        ll res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res += gcd(v[i], v[j]);
            }
        }
        cout << res << '\n';
    }

    return 0;
}