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

    vector<ll> lis(n);
    ll idx = 0;
    lis[0] = v[0];
    for (int i = 0; i < n; i++) {
        if (lis[idx] < v[i]) lis[++idx] = v[i];
        else {
            ll idx2 = lower_bound(lis.begin(), lis.begin() + idx, v[i]) - lis.begin();
            lis[idx2] = v[i];
        }
    }

    cout << idx + 1;

    return 0;
}