#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

int arr[1003][1003];
int res[1003][1003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = -1;
    res[0][0] = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + 1][j] = max(res[i + 1][j], res[i][j] + arr[i + 1][j]);
            res[i][j + 1] = max(res[i][j + 1], res[i][j] + arr[i][j + 1]);
            res[i + 1][j + 1] = max(res[i + 1][j + 1], res[i][j] + arr[i + 1][j + 1]);

            cnt = max(cnt, res[i + 1][j]);
            cnt = max(cnt, res[i][j + 1]);
            cnt = max(cnt, res[i + 1][j + 1]);
        }
    }

    cout << cnt;

    return 0;
}