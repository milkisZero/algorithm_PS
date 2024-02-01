#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, c;
int arr[13];
int dp[11][21][1 << 13];

int solve(int bag, int weight, int visited) {
    // 마지막 가방을 넘어가면 -1로 숫자를 맞춰준다
    if (bag == m)
        return -1;
    // 0부터 n-1이 다 차있는 경우
    if (visited == (1 << n) - 1)
        return 0;

    // cpp -> &, 별명을 설정한다(유사포인터)
    int &ret = dp[bag][weight][visited];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < n; i++) {
        // i번 보석이 이미 체크되어있는 경우
        if (visited & (1 << i))
            continue;
        else if (arr[i] > c)
            continue;
        else if (weight + arr[i] > c)
            // 다음 가방에 담기
            ret = max(ret, solve(bag + 1, arr[i], visited | (1 << i)) + 1);
        else
            ret = max(ret, solve(bag, weight + arr[i], visited | (1 << i)) + 1);
    }
    return ret;
}

int main() {
    fastio();

    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0);

    return 0;
}