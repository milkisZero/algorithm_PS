#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int d[25][25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp = d[i][j];
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j)
                    continue;
                if (d[i][j] == d[i][k] + d[k][j])
                    tmp = 0;

                if (d[i][j] > d[i][k] + d[k][j]) {
                    cout << -1;
                    return 0;
                }
            }
            res += tmp;
        }
    }

    cout << res / 2;

    return 0;
}