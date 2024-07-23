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

    ll n;
    cin >> n;

    vector<ll> psum(n + 1, 0);
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }

    priority_queue<pll, vector<pll>, greater<pll>> mn;
    priority_queue<ll> mx;

    // dp(j) + pj ≤ pi를 만족하는 j 중 pj 의 최댓값
    // dp(j) + pj > pi인 j 들만 들고 있다가 i가 증가해서 처음 <=이 되는 j를 pop, mx에 넣음
    for (int i = 1; i <= n; i++) {
        while (!mn.empty() && mn.top().first <= psum[i]) {
            mx.push(psum[mn.top().second]);
            mn.pop();
        }

        dp[i] = psum[i];
        if (!mx.empty()) dp[i] -= mx.top();

        mn.push({dp[i] + psum[i], i});
    }

    ll res = LLINF;
    for (int i = 1; i <= n; i++) {
        res = min(res, max(dp[i], psum[n] - psum[i]));
    }

    cout << res;

    return 0;
}