#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<pll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin() + 1, v.end());

    ll pref[n + 1] = {0}, pref2[n + 1] = {0};
    ll cnt1 = v[1].second, cnt2 = v[n].second;
    for (int i = 2; i <= n; i++) {
        cnt1 += (v[i].first - v[i - 1].first) * (i - 1);
        cnt1 += v[i].second;

        cnt2 += (v[n + 2 - i].first - v[n + 1 - i].first) * (i - 1);
        cnt2 += v[n + 1 - i].second;

        pref[i] = pref[i - 1] + (v[i].first - v[i - 1].first);
        pref2[i] = pref2[i - 1] + (v[n + 2 - i].first - v[n + 1 - i].first);
    }

    ll a = max(v[n].second + (n - 1) * (v[n].first - v[n - 1].first), v[1].second + 1 * (v[2].first - v[1].first) + pref[n] - pref[2]);
    ll b = max(v[1].second + (n - 1) * (v[2].first - v[1].first), v[n].second + 1 * (v[n].first - v[n - 1].first + pref2[n] - pref2[2]));
    ll res = min(cnt1 - a, cnt2 - b);

     for (int i = 2; i < n; i++) {
        ll tmp = cnt1 - v[i].second - v[n].first + v[i].first;
        ll tmp2 = cnt2 - v[n + 1 - i].second - v[n + 1 - i].first + v[1].first;
        res = min(res, min(tmp, tmp2));
    }


    cout << res;

    return 0;
}