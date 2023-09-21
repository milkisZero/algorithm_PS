#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int arr[40004];
int res[40004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (res[idx] < arr[i])
            res[++idx] = arr[i];
        else {
            int idx2 = lower_bound(res, res + idx, arr[i]) - res;
            res[idx2] = arr[i];
        }
    }

    cout << idx;

    return 0;
}