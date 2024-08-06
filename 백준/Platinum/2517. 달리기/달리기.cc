#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[500005];
ll n;

ll sum(ll i) {
    ll ans = 0;
    while (i > 0) {
        ans += arr[i];
        i -= (i & -i);
    }
    return ans;
}

void update(ll i, ll num) {
    while (i <= n) {
        arr[i] += num;
        i += (i & -i);
    }
}

int main() {
    fastio;

    cin >> n;
    vector<pll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        v[i].first = i + 1;
    }
    sort(v.begin(), v.end(), [&](pll a, pll b) { return a.second < b.second; });

    for (int i = 0; i < n; i++) {
        cout << (i + 1) - sum(v[i].first - 1) << '\n';
        update(v[i].first, 1);
    }

    return 0;
}