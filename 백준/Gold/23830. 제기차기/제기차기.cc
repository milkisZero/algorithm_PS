#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[100005];
ll n, p, q, r, S;

ll calc(ll k) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > k + r) sum -= p;
        else if (arr[i] < k) sum += q;
    }
    return sum;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> p >> q >> r >> S;

    ll L = 1, R = 110000, M;
    while (L < R) {
        M = (L + R) / 2;
        if (calc(M) >= S) R = M;
        else L = M + 1;
    }

    if (R == 110000) cout << -1;
    else cout << R;

    return 0;
}