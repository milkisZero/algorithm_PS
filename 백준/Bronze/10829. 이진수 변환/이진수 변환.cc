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

    string res;
    for (int i = 0; n; i++) {
        int k = (n & 1);
        res = to_string(k) + res;
        n >>= 1;
    }

    cout << res;

    return 0;
}