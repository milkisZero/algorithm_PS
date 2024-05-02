#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

bool cmp(pll a, pll b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main() {
    fastio;

    ll n, m, a, b;
    cin >> n >> m;
    vector<pll> pic(n);
    vector<ll> frame(m);

    for (auto &[a, b] : pic) cin >> a >> b;
    for (auto &a : frame) cin >> a;

    sort(frame.begin(), frame.end(), greater<>());
    sort(pic.begin(), pic.end(), cmp);

    ll res = 0, idx = 0;
    for (auto [a, b] : pic) {
        if (a <= frame[idx]) res++, idx++;
        if (idx == m) break;
    }
    cout << res;

    return 0;
}