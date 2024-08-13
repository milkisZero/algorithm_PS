#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll n;
    cin >> n;

    while (1) {
        ll sum = 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) sum += (n / i);
            }
        }

        ll k = 1;
        for (int i = 2; i <= sqrt(sum); i++) {
            if (sum % i == 0) {
                k += i;
                if (i != sum / i) k += (sum / i);
            }
        }

        if (k == n && sum != n) {
            cout << k << ' ' << sum;
            return 0;
        }
        n++;
    }

    return 0;
}