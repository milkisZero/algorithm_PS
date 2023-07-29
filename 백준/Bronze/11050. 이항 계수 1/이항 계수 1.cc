#include <iostream>
using namespace std;

int fact[15];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    cout << fact[n] / (fact[k] * fact[n - k]);

    return 0;
}