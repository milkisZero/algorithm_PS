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

    vector<ll> v(n), lis(n), index(n);
    for (auto &e : v) cin >> e;

    ll idx = 0;
    lis[0] = v[0], index[0] = 0;
    for (int i = 1; i < n; i++) {
        if (lis[idx] < v[i]) lis[++idx] = v[i], index[i] = idx;
        else {
            ll idx2 = lower_bound(lis.begin(), lis.begin() + idx, v[i]) - lis.begin();
            lis[idx2] = v[i], index[i] = idx2;
        }
    }

    ll tmp = idx;
    for (int i = n - 1; i >= 0; i--) {
        if (tmp == index[i]) lis[index[i]] = v[i], tmp--;
    }

    cout << idx + 1 << '\n';
    for (int i = 0; i <= idx; i++) cout << lis[i] << ' ';

    return 0;
}