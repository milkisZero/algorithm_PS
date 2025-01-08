// #트리dp #dfs #dp
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

vector<ll> v[55];
ll visited[55];
ll cnt[55];

ll dfs(ll cur) {
    visited[cur] = 1;

    for (auto e : v[cur]) {
        if (!visited[e]) dfs(e);
    }

    sort(v[cur].begin(), v[cur].end(), [](ll a, ll b) { return cnt[a] > cnt[b]; });

    ll k = 0, sum = 0;
    for (auto e : v[cur]) {
        sum = max(sum, k++ + cnt[e]);
    }

    return cnt[cur] = sum + 1;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        if (tmp > -1) v[tmp].push_back(i);
    }

    cout << dfs(0) - 1;

    return 0;
}