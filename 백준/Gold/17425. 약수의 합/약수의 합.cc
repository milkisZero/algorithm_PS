#include <iostream>
using namespace std;

int arr[1000005];
long long prefix[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= 1000000; i++) {
        for (int j = 1; j * i <= 1000000; j++) {
            arr[j * i] += i;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    while (t--) {
        int n;
        cin >> n;
        cout << prefix[n] << '\n';
    }

    return 0;
}