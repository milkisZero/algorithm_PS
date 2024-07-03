#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll par[500005];

void init(ll n) {
    for (int i = 0; i < n; i++) par[i] = i;
}

ll find(ll a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void uni(ll a, ll b) {
    if (a > b) swap(a, b);
    if (find(a) != find(b)) par[find(a)] = find(b);
}

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    init(n);

    for (int i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;

        if (find(a) == find(b)) {
            cout << i;
            return 0;
        }

        uni(a, b);
    }

    cout << 0;

    return 0;
}