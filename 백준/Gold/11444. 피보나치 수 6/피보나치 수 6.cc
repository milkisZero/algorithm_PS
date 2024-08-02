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

    ll n;
    cin >> n;

    matrix A = {{1, 1}, {1, 0}};
    matrix res = {{1, 0}, {0, 1}};

    while (n) {
        if (n % 2) res = res * A;
        n /= 2;
        A = A * A;
    }

    cout << res[1][0];

    return 0;
}