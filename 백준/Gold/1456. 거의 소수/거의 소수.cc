#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll prime[(ll)1e7 + 7];

int main() {
    fastio;

    ll a, b;
    cin >> a >> b;

    ll k = sqrt(b);
    for (int i = 2; i <= sqrt(k); i++) {
        if (prime[i]) continue;
        for (int j = 2; j * i <= k; j++) {
            prime[i * j] = 1;
        }
    }

    ll cnt = 0;
    for (int i = 2; i <= k; i++) {
        if (prime[i]) continue;

        for (int j = 2; pow(i, j) <= b; j++) {
            if (pow(i, j) >= a) cnt++;
        }
    }
    cout << cnt;

    return 0;
}