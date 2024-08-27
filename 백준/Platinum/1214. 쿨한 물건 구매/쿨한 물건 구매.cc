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

    ll a, b, c;
    cin >> a >> b >> c;

    ll mini = LLINF;
    if (b < c) swap(b, c);
    for (int i = 0; i <= (a / b) + 1; i++) {
        ll k = a - b * i;
        ll p = k / c;
        if (k % c) p++;
        if (k < 0) p = 0;
        mini = min(mini, b * i + c * p);
        if (i == c) break;
    }
    cout << mini;

    return 0;
}