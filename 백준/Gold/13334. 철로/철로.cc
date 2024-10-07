#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

struct cmp {
    bool operator()(pll a, pll b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

vector<pll> v;
priority_queue<pll, vector<pll>, greater<pll>> pq;
priority_queue<pll, vector<pll>, cmp> pq_max;

int main() {
    fastio;

    ll N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        v.push_back({x, y});
    }
    ll d;
    cin >> d;

    sort(v.begin(), v.end(), [](pll a, pll b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    ll now = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].second - v[i].first > d) continue;

        pq.push({v[i].first, v[i].second});

        while (!pq.empty()) {
            if (pq.top().first < v[i].second - d) pq.pop();
            else break;
        }

        if (ans < pq.size()) ans = pq.size();
    }

    sort(v.begin(), v.end(), [](pll a, pll b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    now = N - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (v[i].second - v[i].first > d) continue;

        pq_max.push({v[i].first, v[i].second});

        while (!pq_max.empty()) {
            if (pq_max.top().second > v[i].first + d) pq_max.pop();
            else break;
        }

        if (ans < pq_max.size()) ans = pq_max.size();
    }

    cout << ans;

    return 0;
}