#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

// i번째에서 2^j번 이동한 후 정점
ll sparse[500005][20];

int main() {
    fastio;

    ll m;
    cin >> m;

    for (int i = 1; i <= m; i++) cin >> sparse[i][0];

    // j를 기준으로 채운다
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= m; i++) {
            sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
        }
    }

    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        // 2진수에서 1이 위치한 것 체크 = 2의 제곱수의 합
        for (int i = 0; a > 0; i++) {
            if (a & 1) b = sparse[b][i];
            a >>= 1;
        }

        cout << b << '\n';
    }

    return 0;
}