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

    vector<ll> v(n);
    for (auto &e : v) cin >> e;

    ll cnt = 0, prev = 0;
    for (int i = 1; i < n; i++) {

        ll a = ceil(log2((double)v[i - 1] / v[i]) + prev);
        a = max(a, 0ll);

        cnt += a;
        prev = a;
    }

    cout << cnt;

    return 0;
}