#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MOD 1000

using matrix = vector<vector<ll>>;
ll n, m;

matrix operator*(const matrix &a, const matrix &b) {
    matrix ret(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll tmp = 0;
            for (int l = 0; l < n; l++) {
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

    cin >> n >> m;

    matrix A(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    matrix res(n, vector<ll>(n));
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (m) {
        if (m % 2) res = res * A;
        m /= 2;
        A = A * A;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}