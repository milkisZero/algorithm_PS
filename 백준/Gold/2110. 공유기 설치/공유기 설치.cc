#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[200005];

int bs(int k, int n) {
    int l = 1, r = arr[n - 1] - arr[0], m;
    int res = -1;

    while (l <= r) {
        m = (l + r) / 2;

        int cnt = 1, point = arr[0];
        for (int i = 1; i < n; i++) {
            if (point + m <= arr[i]) {
                cnt++;
                point = arr[i];
            }
        }

        if (cnt >= k) {
            l = m + 1;
            res = m;
        }
        else
            r = m - 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << bs(c, n);

    return 0;
}