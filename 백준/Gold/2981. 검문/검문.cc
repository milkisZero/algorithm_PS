#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

long long arr[105];
long long arr2[105];

long long gcd(long long a, long long b) {
    long long r;
    do {
        if (a < b)
            swap(a, b);

        r = a % b;
        a = r;

    } while (r);

    return b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int idx = 0;
    for (int i = 0; i < n - 1; i++) {
        arr2[idx++] = abs(arr[i + 1] - arr[i]);
    }

    long long num = arr2[0];
    for (int i = 1; i < idx; i++) {
        num = gcd(num, arr2[i]);
    }

    set<int> res;
    for (int i = 1; i < sqrt(num) + 1; i++) {
        if (num % i == 0) {
            res.insert(i);
            res.insert(num / i);
        }
    }

    for (auto i = res.begin(); i != res.end(); i++) {
        if (*i != 1)
            cout << *i << ' ';
    }

    return 0;
}