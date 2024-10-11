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

    ll n, k;
    cin >> n >> k;

    vector<pll> v;
    v.push_back({0, 1});
    v.push_back({1, 1});

    int i = 0;
    while (i < k) {
        auto [a, b] = v[i];
        auto [c, d] = v[i + 1];
        if (b + d <= n) v.insert(v.begin() + i + 1, {a + c, b + d});
        else i++;
    }

    cout << v[k - 1].first << ' ' << v[k - 1].second;

    return 0;
}