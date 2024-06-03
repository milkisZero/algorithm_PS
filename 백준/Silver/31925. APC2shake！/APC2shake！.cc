#include <bits/stdc++.h>
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
    fastio;

    ll t;
    cin >> t;

    vector<pair<string, ll>> v;

    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        ll n, m;
        cin >> n >> m;

        if (b == "hewhak") continue;
        if (c == "winner") continue;
        if (n != -1 && n <= 3) continue;

        v.push_back({a, m});
    }

    sort(v.begin(), v.end(), [](pair<string, ll> a, pair<string, ll> b) {
        return a.second < b.second;
    });

    vector<string> res;
    for (auto [a, b] : v) {
        res.push_back(a);
        if (res.size() == 10) break;
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto e : res) cout << e << '\n';

    return 0;
}