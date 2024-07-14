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

    ll n, d;
    cin >> n >> d;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll a = v[0], b = v[n - 1];

    if (a * b > 0 && a > 0) a = 0;
    if (a * b > 0 && a < 0) b = 0;
    a = abs(a), b = abs(b);

    ll res = LLINF;
    if (a + b + b + a >= d) res = min(res, 4 * a + 4 * b);
    else res = min(res, 4 * a + 4 * b + (d - (a + b + b + a)));

    cout << min(min(res, 2 * a + 2 * b + 2 * d), min(4 * a + 2 * b + d, 2 * a + 4 * b + d));

    return 0;
}