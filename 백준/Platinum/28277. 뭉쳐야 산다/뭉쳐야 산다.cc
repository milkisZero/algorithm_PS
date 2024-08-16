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

    ll n, q;
    cin >> n >> q;

    set<ll> st[n];
    for (int i = 0; i < n; i++) {
        ll m;
        cin >> m;
        while (m--) {
            ll k;
            cin >> k;
            st[i].insert(k);
        }
    }

    while (q--) {
        ll a, b, c;
        cin >> a >> b;

        if (a == 1) {
            cin >> c;

            if (st[b - 1].size() < st[c - 1].size()) swap(st[b - 1], st[c - 1]);
            for (auto e : st[c - 1]) {
                st[b - 1].insert(e);
            }
            st[c - 1].clear();
        }
        else cout << st[b - 1].size() << '\n';
    }

    return 0;
}