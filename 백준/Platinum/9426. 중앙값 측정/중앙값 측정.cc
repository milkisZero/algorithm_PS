#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    ordered_set OS;
    vector<ll> v(n + 1, 0);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i]++;

        OS.insert({v[i], i});
        if (i >= k) {
            OS.erase({v[i - k], i - k});
            sum += (*OS.find_by_order((k + 1) / 2 - 1)).first - 1;
        }
    }

    cout << sum;

    return 0;
}