#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[45];
unordered_map<ll, ll> sum;
ll n, k, res;

void left_recur(ll idx, ll val) {
    if (idx == n / 2) {
        sum[val]++;
        return;
    }
    left_recur(idx + 1, val + arr[idx]);
    left_recur(idx + 1, val);
}

void right_recur(ll idx, ll val) {
    if (idx == n) {
        res += sum[k - val];
        return;
    }
    right_recur(idx + 1, val + arr[idx]);
    right_recur(idx + 1, val);
}

int main() {
    fastio;

    cin >> n >> k;
    k == 0 ? res-- : 1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    left_recur(0, 0);
    right_recur(n / 2, 0);

    cout << res;

    return 0;
}