#include <iostream>
#include <math.h>
using namespace std;

int arr[5000006];
int prime[5000006];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (arr[i])
            continue;
        for (int j = 2; j <= n / i; j++) {
            arr[j * i] = 1;
        }
    }

    int idx1 = 0;
    for (int i = 2; i <= n; i++) {
        if (!arr[i])
            prime[idx1++] = i;
    }

    int cnt = 0, idx = 0, sum = 0;
    for (int i = 0; i < idx1; i++) {
        sum += prime[i];

        while (idx < i && sum > n) {
            sum -= prime[idx++];
        }

        if (sum == n)
            cnt++;
    }

    cout << cnt;

    return 0;
}