#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000006];
int lis[1000006];

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
        if (lis[j] >= arr[i])
            lis[lower_bound(lis, lis + j, arr[i]) - lis] = arr[i];
        else
            lis[++j] = arr[i];
    }

    cout << j + 1;

    return 0;
}