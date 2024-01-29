#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll child[55];

int main() {
    fastio();

    ll k, h, q;
    cin >> k >> h >> q;

    child[h] = k;
    for (int i = h - 1; i >= 1; i--) {
        child[i] = child[i + 1] * (k + 1) + k;
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;

        if (b > child[1]) {
            cout << -1 << '\n';
            continue;
        }
        else if (a == b) {
            cout << 0 << '\n';
            continue;
        }

        int ah = h + 1, bh = h + 1;
        for (ll i = 1; i < h; i++) {
            if (a % (ll)round(pow(k + 1, i)) == 0)
                ah--;
            if (b % (ll)round(pow(k + 1, i)) == 0)
                bh--;
        }

        ll res = 0;
        ll ak = 0, bk = 0;
        for (int i = 2; i <= h; i++) {
            ak = 0, bk = 0;

            for (int j = 1; j <= k + 1; j++) {
                if (!ak && a < (child[i] * j + j)) {
                    ak = (child[i] * j + j);
                    a -= child[i] * (j - 1) + j - 1;
                }
                else if (!ak && a == (child[i] * j + j)) {
                    ak = -1;
                }

                if (!bk && b < (child[i] * j + j)) {
                    bk = (child[i] * j + j);
                    b -= child[i] * (j - 1) + j - 1;
                }
                else if (!bk && b == (child[i] * j + j)) {
                    bk = -1;
                }
            }
            if (ak == -1 && ak == bk) {
                res = 2;
                cout << res << '\n';
                break;
            }
            else if (ak != bk) {
                res = ah - 1 + bh - 1 - (i - 1 - 1) * 2;
                cout << res << '\n';
                break;
            }
        }

        if (res == 0)
            cout << 2 << '\n';
    }

    return 0;
}