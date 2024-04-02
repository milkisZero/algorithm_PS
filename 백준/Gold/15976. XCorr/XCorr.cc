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

    ll n, m, a, b;
    cin >> n;

    ll idx, val;
    vector<ll> x, xi;
    x.resize(n), xi.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> idx >> val;
        xi[i] = idx;
        x[i] = val;
    }

    cin >> m;
    vector<ll> sumv, yi;
    sumv.resize(m + 1), yi.resize(m);
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> idx >> val;
        yi[i] = idx;
        sum += val;
        sumv[i + 1] = sum;
    }
    cin >> a >> b;

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll s = xi[i] + a, e = xi[i] + b;

        ll sval = lower_bound(yi.begin(), yi.end(), s) - yi.begin();
        ll eval = upper_bound(yi.begin(), yi.end(), e) - yi.begin();

        if (sval < 0)
            sval = 0;
        if (eval < 0)
            eval = 0;

        ll tmp = sumv[eval] - sumv[sval];
        res += tmp * x[i];
    }

    cout << res;

    return 0;
}