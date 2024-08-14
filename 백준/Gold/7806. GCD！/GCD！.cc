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

    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        string a, b;
        iss >> a >> b;
        ll n = stoll(a), k = stoll(b);

        ll res = 1;
        for (ll i = 2; i <= sqrt(k); i++) {
            ll kcnt = 0, ncnt = 0;
            while (k % i == 0) {
                k /= i;
                kcnt++;
            }

            for (ll j = i; j <= n; j *= i) {
                ncnt += n / j;
            }

            res *= pow(i, min(kcnt, ncnt));
        }

        if (k > 1 && k < n) res *= k;
        cout << res << '\n';
    }

    return 0;
}