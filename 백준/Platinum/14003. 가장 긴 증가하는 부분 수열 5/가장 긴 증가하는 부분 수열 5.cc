#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000006];
int lis[1000006];
int index[1000006];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int j = 0;
    lis[0] = arr[0];
    for (int i = 0; i < n; i++) {
        if (lis[j] >= arr[i]) {
            int idx = lower_bound(lis, lis + j, arr[i]) - lis;
            lis[idx] = arr[i];
            index[i] = idx;
        }
        else {
            lis[++j] = arr[i];
            index[i] = j;
        }
    }

    int tmp = j;
    for (int i = n - 1; i >= 0; i--) {
        if (tmp == index[i]) {
            lis[index[i]] = arr[i];
            tmp--;
        }
    }

    cout << j + 1 << '\n';
    for (int i = 0; i <= j; i++) {
        cout << lis[i] << ' ';
    }

    return 0;
}