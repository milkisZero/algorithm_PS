#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll mod = 1000000;
    ll n;
    cin >> n;

    ll sum = 0;
    for (int i = 2; i < n; i++) {
        ll t = n / i;
        if (t >= i) {
            sum += (t * (t + 1) / 2 - i * (i + 1) / 2);
            sum += (t - i + 1) * i;
            sum %= mod;
        }
    }

    cout << sum % mod;

    return 0;
}