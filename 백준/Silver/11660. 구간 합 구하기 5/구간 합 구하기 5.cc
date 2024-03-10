#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int sum[1030][1030];

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp;
            cin >> tmp;
            sum[i][j] = sum[i][j - 1] + tmp;
        }
    }

    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int res = 0;
        for (int i = a; i <= c; i++) {
            res += sum[i][d] - sum[i][b - 1];
        }
        cout << res << '\n';
    }

    return 0;
}