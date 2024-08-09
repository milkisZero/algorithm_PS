// #피보나치 #행렬 거듭제곱
// 피보나치를 행렬로 계산할 수 있다
// {n+1항, n항} = {{1,1}, {1, 0}} ^n * [1,0]
#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MOD (ll)1e9

using matrix = vector<vector<ll>>;

matrix operator*(const matrix &a, const matrix &b) {
    matrix ret(2, vector<ll>(2));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll tmp = 0;
            for (int l = 0; l < 2; l++) {
                tmp += (a[i][l] * b[l][j]) % MOD;
                tmp %= MOD;
            }
            ret[i][j] = tmp;
        }
    }
    return ret;
}

int main() {
    fastio;

    ll n, k, ans = 0;
    cin >> n >> k;

    matrix A = {{1, 1}, {1, 0}};
    matrix res = {{1, 0}, {0, 1}};
    ll t = k + 2;
    while (t) {
        if (t % 2) res = res * A;
        t /= 2;
        A = A * A;
    }
    ans += res[1][0] - 1;
    ans %= MOD;

    A = {{1, 1}, {1, 0}};
    res = {{1, 0}, {0, 1}};
    t = n - 1 + 2;
    while (t) {
        if (t % 2) res = res * A;
        t /= 2;
        A = A * A;
    }
    if (ans >= res[1][0] - 1) ans -= res[1][0] - 1;
    else ans += MOD - (res[1][0] - 1);

    cout << ans % MOD;

    return 0;
}