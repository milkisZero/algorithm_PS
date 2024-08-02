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
ll k, n;

matrix operator*(const matrix &a, const matrix &b) {
    matrix ret(k + 2, vector<ll>(k + 2));

    for (int i = 0; i < k + 2; i++) {
        for (int j = 0; j < k + 2; j++) {
            ll tmp = 0;
            for (int l = 0; l < k + 2; l++) {
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

    cin >> k >> n;

    matrix A(k + 2, vector<ll>(k + 2));
    matrix res(k + 2, vector<ll>(k + 2));

    for (int i = 0; i < k + 2; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = 1;
        }
    }

    for (int i = 0; i < k + 2; i++) res[i][i] = 1;

    n--;
    while (n) {
        if (n % 2) res = res * A;
        n /= 2;
        A = A * A;
    }

    ll sum = 0;
    for (auto e : res[k + 1]) {
        sum += e;
        sum %= MOD;
    }
    cout << sum;

    return 0;
}