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

    ll m, n, k;
    cin >> m >> n >> k;

    vector<pll> v(k);
    for (auto &e : v) {
        ll a, b;
        cin >> a >> b;
        e = {a, b};
    }

    sort(v.begin(), v.end());

    vector<ll> v2(k);
    for (int i = 0; i < k; i++) v2[i] = v[k - 1 - i].second;

    vector<ll> lis(k);
    ll idx = 0;
    lis[0] = v2[0];
    for (int i = 1; i < k; i++) {
        if (lis[idx] < v2[i]) lis[++idx] = v2[i];
        else {
            ll idx2 = lower_bound(lis.begin(), lis.begin() + idx, v2[i]) - lis.begin();
            lis[idx2] = v2[i];
        }
    }

    cout << idx + 1;

    return 0;
}