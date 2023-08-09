#include <iostream>
using namespace std;

int arr[10006];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0, cnt = 0;
    for (int i = 0, j = 0; i < n;) {
        if (sum < m && j < n) {
            sum += arr[j];
            j++;
        }
        else {
            if (sum == m)
                cnt++;
            sum -= arr[i];
            i++;
        }
    }

    cout << cnt;

    return 0;
}