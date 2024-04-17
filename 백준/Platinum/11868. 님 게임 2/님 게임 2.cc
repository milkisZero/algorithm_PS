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

    ll n, k, res = -1;
    cin >> n;

    while (n--) {
        cin >> k;
        if (res == -1) res = k;
        else res = res ^ k;
    }

    if (res) cout << "koosaga";
    else cout << "cubelover";

    return 0;
}