#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

string arr[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;

        // 각 행의 0의 개수 카운트
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '0')
                cnt++;
        }

        // 크기가 k이하이고 홀짝이 같다면 같은 모양의 행을 카운트
        if (cnt <= k && k % 2 == cnt % 2) {
            int cnt2 = 0;
            for (int j = 0; j < n; j++) {
                if (arr[i] == arr[j])
                    cnt2++;
            }
            res = max(res, cnt2);
        }
    }

    cout << res;

    return 0;
}