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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll a = v[0], b = v[1];
    for (int i = 1; i < n - 1; i++) {
        a = 2 * v[i] - a;
        b = 2 * v[i] - b;
        swap(a, b);
        if (b > v[i + 1]) b = v[i + 1];
        if (a < v[i]) a = v[i];
    }
    if (a > b) cout << 0;
    else cout << b - a + 1;

    return 0;
}