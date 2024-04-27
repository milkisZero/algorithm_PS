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

bool calc(ll k) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > k + r) sum -= p;
        else if (arr[i] < k) sum += q;
    }
    if (sum < S) return 0;
    return 1;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> p >> q >> r >> S;

    ll L = 1, R = 100001, M, res = -1;
    while (L <= R) {
        M = (L + R) / 2;
        if (calc(M)) {
            res = M;
            R = M - 1;
        }
        else L = M + 1;
    }

    cout << res;

    return 0;
}