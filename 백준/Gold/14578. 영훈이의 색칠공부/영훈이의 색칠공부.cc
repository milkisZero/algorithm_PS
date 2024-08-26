// #dp #교란수열
// 교란수열의 점화식을 사용하는 문제
#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MOD 1000000007

ll dp[100005];

int main() {
    fastio;

    ll n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 0;

    ll fact = 1;
    for (int i = 2; i <= n; i++) {
        fact = (fact * i) % MOD;
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    }

    cout << (fact * dp[n]) % MOD;

    return 0;
}