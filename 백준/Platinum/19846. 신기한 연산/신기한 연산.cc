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

    ll n, m, q;
    cin >> n >> m >> q;

    vector<pll> v(q);
    for (auto &e : v) cin >> e.first >> e.second;

    char str[m] = {0};
    char c = 'a';
    for (int i = 0; i < m; i++) {
        str[i] = c;

        if (i % 2) {
            if (c + 1 >= 'a' + n) c = 'a';
            else c++;
        }
    }

    for (auto e : str) cout << e;

    return 0;
}