#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<pair<pll, pll>> v;
ll par[200005];

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
    v.resize(n);
    vector<pair<pll, ll>> xinfo, yinfo;
    init(n);

    for (int i = 0; i < n; i++) {
        auto &[x, y] = v[i];

        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c) swap(a, c);
        if (b > d) swap(b, d);
        x = {a, c}, y = {b, d};

        xinfo.push_back({{a, c}, i});
        yinfo.push_back({{b, d}, i});
    }

    sort(xinfo.begin(), xinfo.end());
    sort(yinfo.begin(), yinfo.end());

    auto [X, num] = xinfo[0];
    for (int i = 1; i < n; i++) {
        auto [x, k] = xinfo[i];
        if (x.first <= X.second || x.second <= X.second) {
            uni(num, k);
            if (X.second < x.second) X.second = x.second;
        }
        else {
            X = xinfo[i].first;
            num = xinfo[i].second;
        }
    }

    auto [Y, num2] = yinfo[0];
    for (int i = 1; i < n; i++) {
        auto [y, k] = yinfo[i];
        if (y.first <= Y.second || y.second <= Y.second) {
            uni(num2, k);
            if (Y.second < y.second) Y.second = y.second;
        }
        else {
            Y = yinfo[i].first;
            num2 = yinfo[i].second;
        }
    }

    while (m--) {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        if (find(a) == find(b)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}