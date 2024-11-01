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

vector<ll> v[1003];
ll dp[339][1003];

priority_queue<ll> pq;

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        v[i].resize(n + 1);
        for (int j = 1; j <= n; j++) cin >> v[i][j];
    }

    for (int i = 0; i < n; i++) {
        memset(dp, 0, sizeof(dp));

        ll l = min(k, 333ll);
        for (int j = 1; j <= l; j++) {
            ll sum = 0;
            for (int idx = 1; idx <= n; idx++) {
                sum += v[i][idx];
                if (idx >= 3) {
                    dp[j][idx] = max(dp[j][idx - 1], dp[j - 1][idx - 3] + sum);
                    sum -= v[i][idx - 2];
                }
            }
            // pq.push({dp[j][n] / j, j, dp[j][n], i});
        }
        for (int j = 1; j <= l; j++) {
            pq.push(dp[j][n] - dp[j - 1][n]);
        }
    }

    ll sum = 0, acnt = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
        acnt++;
        if (acnt == k) break;
    }

    cout << sum;

    return 0;
}