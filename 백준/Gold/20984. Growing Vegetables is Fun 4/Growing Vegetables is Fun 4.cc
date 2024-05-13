#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 200000

ll arr[MAX + 3], up[MAX + 3], low[MAX + 3];

int main() {
    fastio;

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 1; i < n; i++) {
        up[i] = up[i - 1] + max(0ll, arr[i - 1] - arr[i] + 1);
    }

    for (int i = n - 2; i >= 0; i--) {
        low[i] = low[i + 1] + max(0ll, arr[i + 1] - arr[i] + 1);
    }

    ll res = LLINF;
    for (int i = 0; i < n; i++) {
        res = min(res, max(low[i], up[i]));
    }
    cout << res;

    return 0;
}