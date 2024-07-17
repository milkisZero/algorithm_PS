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
    cin >> n;

    vector<ll> v(n);

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i]) cnt++;
    }

    ll idx = 0;
    deque<ll> dq;
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        if (v[i]) continue;
        dq.push_back(k);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        ll k;
        cin >> k;

        dq.push_front(k);
        ll tmp = dq.back();
        dq.pop_back();
        cout << tmp << ' ';
    }

    return 0;
}