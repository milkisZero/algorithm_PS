// #dp #lcs
// 배열을 역추적하는 방식
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int a_leng = a.length();
    int b_leng = b.length();
    for (int i = 0; i < a_leng; i++) {
        for (int j = 0; j < b_leng; j++) {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[a_leng][b_leng] << '\n';

    string res;
    int i = a_leng, j = b_leng;
    while (dp[i][j] != 0) {
        if (dp[i][j] == dp[i][j - 1])
            j--;
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            res = res + a[i - 1];
            i--, j--;
        }
    }

    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}