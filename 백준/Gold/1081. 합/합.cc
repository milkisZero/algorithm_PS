#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll ucnt[11];
ll lcnt[11];

void func(ll n, ll cnt[]) {
    int k = n;
    for (int j = 0; k; j++) {
        int tmp = k % 10;
        k /= 10;

        for (int i = 0; i < 10; i++) {
            if (i == tmp) {
                cnt[i] += n - (round(pow(10, j + 1)) * k + tmp * round(pow(10, j))) + 1;
                if (tmp == 0)
                    cnt[i] += round(pow(10, j)) * (k - 1);
                else
                    cnt[i] += round(pow(10, j)) * k;
            }
            else if (tmp < i || i == 0 || tmp == 0) {
                cnt[i] += round(pow(10, j)) * k;
            }
            else if (i > 0 && i < tmp) {
                cnt[i] += round(pow(10, j)) * (k + 1);
            }
        }
    }
}

int main() {
    fastio;

    ll l, u;
    cin >> l >> u;

    func(l - 1, lcnt), func(u, ucnt);

    ll res = 0;
    for (int i = 0; i < 10; i++) {
        res += i * (ucnt[i] - lcnt[i]);
    }

    cout << res;

    return 0;
}