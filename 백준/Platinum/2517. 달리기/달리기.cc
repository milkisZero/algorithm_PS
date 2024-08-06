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
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    fastio;

    ll n, e;
    cin >> n;

    ordered_set OS;
    for (int i = 1; i <= n; i++) {
        cin >> e;
        OS.insert(e);
        cout << i - OS.order_of_key(e) << '\n';
    }

    return 0;
}