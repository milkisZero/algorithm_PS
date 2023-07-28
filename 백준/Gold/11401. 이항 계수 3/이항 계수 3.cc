#include <iostream>
using namespace std;
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long fact = 1;
    for (int i = n - k + 1; i <= n; i++)
        fact = (fact * i) % MOD;

    long long invFact = 1;
    for (int i = 1; i <= k; i++)
        invFact = (invFact * i) % MOD;

    long long powN = MOD - 2;
    while (powN) {
        if (powN % 2)
            fact = (fact * invFact) % MOD;
        powN /= 2;
        invFact = (invFact * invFact) % MOD;
    }

    cout << fact;

    return 0;
}