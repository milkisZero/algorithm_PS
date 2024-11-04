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

    map<ll, ll> mp;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }

    priority_queue<pll> pq;
    for (auto [a, b] : mp) {
        pq.push({-a, b});
    }

    ll k;
    cin >> k;

    ll maxi = -1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) maxi = max(maxi, v[i]);
    }

    ll res = 0, prev = 0;
    while (k > 0) {
        auto [val, cnt] = pq.top();
        pq.pop();

        cnt += prev;
        val = -val;

        if (pq.empty()) {
            // cout << k << sp << n << endl;
            res += k / n;
            break;
        }

        k -= (-pq.top().first - val) * cnt;
        if (k < 0) {
            k += (-pq.top().first - val) * cnt;
            if (maxi == -1) res += k / cnt;
            break;
        }

        if (maxi == -1) res += (-pq.top().first - val);
        else if (maxi == -pq.top().first) {
            res++;
            maxi = -1;
        }

        prev = cnt;
        // cout << res << endl;
    }
    cout << res;

    return 0;
}