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

    int n;
    cin >> n;

    int cnt = 0;
    while (n) {
        if (n & 1) cnt++;
        n >>= 1;
    }

    if (cnt == 1) cout << 1;
    else cout << 0;

    return 0;
}