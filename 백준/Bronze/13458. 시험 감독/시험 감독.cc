#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &e : v) cin >> e;

    ll b, c;
    cin >> b >> c;

    ll res = 0;
    for (auto e : v) {
        res++;

        if (e <= b) continue;
        e -= b;

        res += (e / c) + bool(e % c);
    }
    cout << res;

    return 0;
}