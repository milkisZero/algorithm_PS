#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define MAX 2000000

int arr[2000007];
vector<ll> v;

int isPrime(ll n) {
    ll limit = min(n, (ll)MAX);

    for (int i = 0; i < v.size() && v[i] < limit; i++) {
        if (n % v[i] == 0)
            return 0;
    }
    return 1;
}

int main() {
    fastio;

    for (ll i = 2; i < MAX; i++) {
        if (arr[i])
            continue;
        for (ll j = 2; j * i < MAX; j++) {
            arr[i * j] = 1;
        }
        if (arr[i] == 0)
            v.push_back(i);
    }

    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;

        if ((a + b) % 2 == 0) {
            if (a == 1 && b == 1)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
        else {
            if (a + b == 3)
                cout << "NO" << '\n';
            else if (isPrime(a + b - 2))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}