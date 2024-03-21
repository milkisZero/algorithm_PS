#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int arr[100005];
int n, res = INF;

void recur(int prev, int idx, int cnt, int val) {
    if (idx == n + 1) {
        res = min(res, cnt);
        return;
    }

    for (int i = -1; i <= 1; i++) {
        if (arr[idx] + i - prev == val || idx <= 2) {
            int k = cnt;
            if (i != 0)
                k++;
            recur(arr[idx] + i, idx + 1, k, arr[idx] + i - prev);
        }
    }
}

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (n <= 2) {
        cout << 0;
        return 0;
    }

    recur(0, 1, 0, INF);

    if (res == INF)
        cout << -1;
    else
        cout << res;

    return 0;
}