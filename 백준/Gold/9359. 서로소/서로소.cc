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

    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        ll a, b, n;
        cin >> a >> b >> n;

        vector<ll> v;
        ll tmp = n;
        for (int j = 2; j <= sqrt(n); j++) {
            if (tmp % j == 0) v.push_back(j);
            while (tmp % j == 0) {
                tmp /= j;
            }
        }
        if (tmp > 1) v.push_back(tmp);

        ll cnt = 0;
        ll k = 1;
        while (k != (1 << v.size())) {
            tmp = k;
            ll tmp2 = 1;
            ll cnt2 = 0;
            for (int j = 0; tmp && j < v.size(); j++) {
                if (tmp & 1) {
                    tmp2 *= v[j];
                    cnt2++;
                }
                tmp >>= 1;
            }

            ll b1 = b / tmp2;
            ll a1 = (a - 1) / tmp2;

            if (cnt2 % 2) cnt += b1 - a1;
            else cnt -= b1 - a1;

            k++;
        }

        cout << "Case #" << i << ": " << b - a + 1 - cnt << '\n';
    }

    return 0;
}