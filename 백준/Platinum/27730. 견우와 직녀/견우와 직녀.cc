#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<pll> e1[100005];
ll n;

ll visited[100005];
ll dp[100005][2];
ll root_val[100005];

void dfs(int cur) {
    visited[cur] = 1;
    for (auto [next, val] : e1[cur]) {
        if (visited[next])
            continue;
        dfs(next);
        dp[cur][0] += dp[next][0] + val * dp[next][1];
        dp[cur][1] += dp[next][1];
    }

    dp[cur][1]++;
}

void dfs2(int cur, int par, int w) {
    visited[cur] = 1;
    if (par) root_val[cur] = root_val[par] - w * dp[cur][1] + w * (n - dp[cur][1]);

    for (auto [next, val] : e1[cur]) {
        if (visited[next])
            continue;
        dfs2(next, cur, val);
    }
}

int main() {
    fastio;

    ll mini[2] = {LLINF, LLINF};
    ll tree[2];
    ll cnt[2];

    for (int t = 0; t < 2; t++) {
        cin >> n;
        cnt[t] = n;
        for (int i = 1; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            e1[a].push_back({b, c});
            e1[b].push_back({a, c});
        }

        dfs(1);
        root_val[1] = dp[1][0];
        memset(visited, 0, sizeof(visited));
        dfs2(1, 0, 0);

        for (int i = 1; i <= n; i++) {
            if (mini[t] > root_val[i]) {
                tree[t] = i;
                mini[t] = root_val[i];
            }
        }

        memset(visited, 0, sizeof(visited));
        memset(root_val, 0, sizeof(root_val));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            e1[i].clear();
        }
    }

    cout << tree[0] << sp << tree[1] << endl;
    cout << cnt[1] * mini[0] + cnt[0] * mini[1] + cnt[0] * cnt[1];

    return 0;
}