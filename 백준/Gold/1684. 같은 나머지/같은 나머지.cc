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

    sort(v.begin(), v.end());

    vector<ll> diff;
    for (int i = 1; i < n; i++) {
        diff.push_back(v[i] - v[0]);
    }

    ll res = gcd(diff[0], diff[1]);
    for (int i = 2; i < n - 1; i++) {
        res = gcd(res, diff[i]);
    }
    cout << res;

    return 0;
}