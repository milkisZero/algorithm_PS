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

    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a == b) cout << 0;
    else cout << b - a - 1 << '\n';
    for (ll i = a + 1; i < b; i++) cout << i << ' ';

    return 0;
}