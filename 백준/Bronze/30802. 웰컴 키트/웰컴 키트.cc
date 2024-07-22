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

    vector<ll> v(6);
    for (auto &e : v) cin >> e;

    ll p, t;
    cin >> t >> p;

    ll tcnt = 0;
    for (auto e : v) {
        ll k = e / t;
        if (e % t) k++;
        tcnt += k;
    }

    cout << tcnt << '\n';
    cout << n / p << ' ' << n % p;

    return 0;
}