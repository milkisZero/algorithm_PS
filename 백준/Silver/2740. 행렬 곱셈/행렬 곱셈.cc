#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

using matrix = vector<vector<ll>>;
ll n, m, k;

matrix operator*(const matrix &a, const matrix &b) {
    matrix ret(n, vector<ll>(k));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            ll tmp = 0;
            for (int l = 0; l < m; l++) {
                tmp += (a[i][l] * b[l][j]);
            }
            ret[i][j] = tmp;
        }
    }
    return ret;
}

int main() {
    fastio;

    cin >> n >> m;

    matrix A(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    cin >> m >> k;
    matrix B(m, vector<ll>(k));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }

    matrix res = A * B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}