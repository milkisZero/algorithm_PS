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

    ll n;
    cin >> n;

    ll k, tmp = 0;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        tmp ^= v[i];
    }

    if (!tmp) cout << '0';
    else {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            ll tmp2 = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                tmp2 ^= v[j];
            }
            for (int j = 0; j <= v[i]; j++) {
                if ((tmp2 ^ j) == 0) res++;
            }
        }

        cout << res;
    }

    return 0;
}