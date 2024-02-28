#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<pll> v;

int main() {
    fastio;

    ll n, k, s;
    cin >> n >> k >> s;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    ll res = 0, cnt = 0;
    for (int i = 0; v[i].first < s && i <= v.size() - 1; i++) {
        if (cnt != 0 && cnt + v[i].second <= k) {
            cnt += v[i].second;
            cnt %= k;
            continue;
        }

        ll tmp = (cnt + v[i].second) / k;
        if (cnt) {
            tmp--;
        }
        cnt += v[i].second;

        if (cnt % k)
            tmp++;
        res += (s - v[i].first) * tmp * 2;
        cnt %= k;
    }

    ll res2 = 0;
    cnt = 0;
    for (int i = v.size() - 1; v[i].first > s && i >= 0; i--) {
        if (cnt != 0 && cnt + v[i].second <= k) {
            cnt += v[i].second;
            cnt %= k;
            continue;
        }

        ll tmp = (cnt + v[i].second) / k;
        if (cnt) {
            tmp--;
        }
        cnt += v[i].second;

        if (cnt % k)
            tmp++;
        res2 += (v[i].first - s) * tmp * 2;
        cnt %= k;
    }

    cout << res + res2;

    return 0;
}