#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fastio;

    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr+3);
    cout << arr[1];
    return 0;
}