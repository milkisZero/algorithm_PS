#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    while (1) {
        ll a, b;
        cin >> a >> b;
        if (!a && !b) break;
        cout << a / b << ' ' << a - (a / b) * b << " / " << b << '\n';
    }

    return 0;
}