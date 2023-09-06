#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1005][1005];
pair<int, int> idx[1005][1005];
char res[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int a_leng = a.length();
    int b_leng = b.length();
    for (int i = 0; i < a_leng; i++) {
        for (int j = 0; j < b_leng; j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                res[i + 1][j + 1] = a[i];
                idx[i + 1][j + 1] = {i, j};
            }
            else {
                if (dp[i][j + 1] > dp[i + 1][j]) {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                    idx[i + 1][j + 1] = idx[i][j + 1];
                    res[i + 1][j + 1] = res[i][j + 1];
                }
                else {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                    idx[i + 1][j + 1] = idx[i + 1][j];
                    res[i + 1][j + 1] = res[i + 1][j];
                }
            }
        }
    }

    cout << dp[a_leng][b_leng] << '\n';
    if (!dp[a_leng][b_leng])
        return 0;

    string tmp;
    tmp = tmp + res[a_leng][b_leng];
    pair<int, int> next = idx[a_leng][b_leng];

    for (int i = 1; i < dp[a_leng][b_leng]; i++) {
        tmp = tmp + res[next.first][next.second];
        next = idx[next.first][next.second];
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp;

    return 0;
}