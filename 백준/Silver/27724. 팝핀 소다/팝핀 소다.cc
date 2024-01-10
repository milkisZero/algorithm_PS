#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int cnt = -1;
    while (n) {
        n /= 2;
        cnt++;
    }

    int res = -1;
    while (k) {
        k /= 2;
        res++;
    }

    if (res + m >= cnt)
        cout << cnt;
    else
        cout << res + m;

    return 0;
}