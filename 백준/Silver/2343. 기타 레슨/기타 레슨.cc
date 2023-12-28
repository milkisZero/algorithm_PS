#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

int arr[100005];
int sum, maxi;

int bs(int n, int disk) {
    int l = maxi, r = sum, m;
    int res = INF;
    while (l <= r) {
        m = (l + r) / 2;

        int s = 0, cnt = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            if (s + arr[i] > m) {
                s2 = max(s2, s);
                cnt++;
                s = arr[i];
            }
            else
                s += arr[i];
        }
        s2 = max(s2, s);
        cnt++;

        if (disk < cnt) {
            l = m + 1;
        }
        else {
            res = min(res, s2);
            r = m - 1;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        maxi = max(maxi, arr[i]);
    }

    cout << bs(n, m);

    return 0;
}