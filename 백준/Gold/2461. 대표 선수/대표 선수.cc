#include <iostream>
#include <algorithm>
using namespace std;

int arr[1003][1003];
int index[1003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
        sort(arr[i], arr[i] + m);
    }

    int check = 0;
    int res = 2147483647;
    while (!check) {
        int mini = 2147483647, min_idx = 0;
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i][index[i]]);

            if (mini > arr[i][index[i]]) {
                mini = arr[i][index[i]];
                min_idx = i;
            }
        }

        res = min(res, maxi - mini);
        index[min_idx]++;

        if (index[min_idx] == m)
            check = 1;
    }

    cout << res;

    return 0;
}