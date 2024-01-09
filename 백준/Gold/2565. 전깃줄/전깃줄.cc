#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

int a[504];
int dp[504];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cin >> a[tmp];
    }

    int res = 0;
    for (int i = 1; i <= 500; i++) {
        if (a[i] == 0)
            continue;
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] == 0)
                continue;

            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << n - res;

    return 0;
}