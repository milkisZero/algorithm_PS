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

    vector<pll> v(n);
    for (auto &e : v) cin >> e.first >> e.second;

    sort(v.begin(), v.end());

    ll res = 1;
    priority_queue<ll, vector<ll>, greater<>> pq;
    pq.push(v[0].second);

    for (int i = 1; i < n; i++) {
        auto [s, t] = v[i];

        if (pq.top() > s) res++;
        else pq.pop();

        pq.push(t);
    }

    cout << res;

    return 0;
}