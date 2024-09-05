#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll par[1000006];
ll np[1000006];

void init() {
    for (int i = 0; i < 1000006; i++) par[i] = -1;
}

ll find(ll a) {
    if (par[a] == -1) return a;
    else return par[a] = find(par[a]);
}

void uni(ll a, ll b) {
    if (find(a) != find(b)) par[find(a)] = find(b);
}

int main() {
    fastio;

    for (int i = 2; i < 1003; i++) {
        if (np[i]) continue;
        for (int j = 2; i * j < 1000006; j++) {
            np[i * j] = 1;
        }
    }

    ll p, a, b;
    cin >> a >> b >> p;
    init();

    for (ll i = p; i < 1000006; i++) {
        if (!np[i]) {

            ll k = i >= a ? i : a / i * i;
            if (k < a) k += i;

            for (ll j = k; j <= b; j += i) {
                uni(k - a, j - a);
            }
        }
    }

    ll cnt = 0;
    for (int i = 0; i <= b - a; i++) {
        if (par[i] == -1) cnt++;
    }
    cout << cnt;

    return 0;
}