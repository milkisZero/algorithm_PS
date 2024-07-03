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

    ll n, m;
    cin >> n >> m;

    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    vector<ll> v;
    ll ans = 0;
    while (!pq.empty()) {
        ll k = pq.top();
        pq.pop();

        if (v.size() == m) {
            ll mini = *min_element(v.begin(), v.end());
            for (auto &e : v) e -= mini;

            sort(v.begin(), v.end(), greater<>());
            v.pop_back();
            ans += mini;
        }

        v.push_back(k);
    }

    ans += *max_element(v.begin(), v.end());
    cout << ans;

    return 0;
}