#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

pll arr[1003];
ll n, k;
int visited[1003];

ll calc(ll a, ll b) {
    auto [a1, a2] = arr[a];
    auto [b1, b2] = arr[b];
    return ceil(sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2)) / 10);
}

int check(ll val) {
    memset(visited, 0, sizeof(visited));
    queue<pll> q;
    q.push({0, 0});
    visited[0] = 1;

    while (!q.empty()) {
        auto [cur, point] = q.front();
        q.pop();

        if (calc(cur, n + 1) <= val)
            return 1;

        for (int i = 1; i <= n; i++) {
            if (i != cur && !visited[i] && calc(cur, i) <= val && point < k) {
                visited[i] = 1;
                q.push({i, point + 1});
            }
        }
    }
    return 0;
}

int main() {
    fastio;

    ll a, b;
    cin >> n >> k;

    arr[n + 1] = {10000, 10000};
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        arr[i] = {a, b};
    }

    ll l = 0, r = calc(0, n + 1), m, res = LLINF;
    while (l <= r) {
        m = (l + r) / 2;
        if (!check(m))
            l = m + 1;
        else {
            r = m - 1;
            res = min(res, m);
        }
    }

    cout << res;

    return 0;
}