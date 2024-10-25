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

ll arr[17][17];
ll dp[17][1 << 17];
ll n;

ll dfs(ll cur, ll visi) {
    if (visi == (1 << n) - 1) {
        if (arr[cur][0] == 0) return INF;
        return arr[cur][0];
    }

    if (dp[cur][visi] != -1) return dp[cur][visi];
    dp[cur][visi] = INF;

    for (int i = 0; i < n; i++) {
        if (arr[cur][i] == 0) continue;
        if (visi & (1 << i)) continue;

        ll visi2 = visi | (1 << i);
        dp[cur][visi] = min(dp[cur][visi], dfs(i, visi2) + arr[cur][i]);
    }
    return dp[cur][visi];
}

int main() {
    fastio;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    fill(&dp[0][0], &dp[16][1 << 16], -1);

    cout << dfs(0, 1);

    return 0;
}