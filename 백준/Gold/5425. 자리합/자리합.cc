// #수학
// 1019 책페이지와 같은 문제
#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll ucnt[11], lcnt[11];

ll pow_t(double n) {
    return round(pow(10, n));
}

void func(ll n, ll cnt[]) {
    ll k = n;
    for (int j = 0; k; j++) {
        ll tmp = k % 10;
        k /= 10;

        for (int i = 0; i < 10; i++) {
            if (i == tmp) {
                cnt[i] += n % pow_t(j) + 1;
                if (tmp == 0) cnt[i] += pow_t(j) * (k - 1);
                else cnt[i] += pow_t(j) * k;
            }
            else if (tmp < i || i == 0) cnt[i] += pow_t(j) * k;
            else if (i < tmp) cnt[i] += pow_t(j) * (k + 1);
        }
    }
}

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {

        ll l, u;
        cin >> l >> u;

        memset(lcnt, 0, sizeof(lcnt));
        memset(ucnt, 0, sizeof(ucnt));

        func(l - 1, lcnt), func(u, ucnt);

        ll res = 0;
        for (int i = 0; i < 10; i++) {
            res += i * (ucnt[i] - lcnt[i]);
        }

        cout << res << '\n';
    }

    return 0;
}