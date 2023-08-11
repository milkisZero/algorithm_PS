#include <iostream>
#include <algorithm>
using namespace std;

int arr[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    cout << arr[0] * arr[n - 1];

    return 0;
}