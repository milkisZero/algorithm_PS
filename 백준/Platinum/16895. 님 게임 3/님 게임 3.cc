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
            if ((tmp ^ v[i]) <= v[i]) res++;
        }

        cout << res;
    }

    return 0;
}