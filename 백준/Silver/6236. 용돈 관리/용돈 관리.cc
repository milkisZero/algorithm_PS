#include <iostream>
using namespace std;

int arr[100005];

int bs(int n, int c) {
    int l = 1, r = 10000 * n, m;
    int res = 2147483647;
    while (l <= r) {
        m = (l + r) / 2;

        int cnt = 1, k = m, check = 0;
        for (int i = 0; i < n; i++) {
            if (m < arr[i]) {
                check = 1;
                break;
            }
            if (k >= arr[i])
                k -= arr[i];
            else {
                cnt++;
                k = m - arr[i];
            }
        }

        if (check || cnt > c)
            l = m + 1;
        else {
            r = m - 1;
            res = min(res, m);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << bs(n, c);

    return 0;
}