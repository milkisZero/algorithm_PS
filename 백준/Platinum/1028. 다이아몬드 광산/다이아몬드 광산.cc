#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

string dia[755];
ll r, c;

bool inmap(ll a, ll b) {
    return a > 0 && b > 0 && a <= r && b <= c;
}

ll lline[755][755], rline[755][755];

int main() {
    fastio;

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        cin >> dia[i];
        dia[i] = " " + dia[i];
    }

    for (int i = r; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            if (dia[i][j] == '1') {
                if (dia[i + 1][j - 1] == '1')
                    lline[i][j] = lline[i + 1][j - 1] + 1;
                else lline[i][j] = 1;

                if (dia[i + 1][j + 1] == '1')
                    rline[i][j] = rline[i + 1][j + 1] + 1;
                else rline[i][j] = 1;
            }
        }
    }

    ll res = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (dia[i][j] == '1') {
                res = max(res, 1ll);

                for (ll k = min(lline[i][j], rline[i][j]); k > 1; k--) {
                    if (inmap(i + k - 1, j - k + 1) && inmap(i + k - 1, j + k - 1)) {
                        if (rline[i + k - 1][j - k + 1] >= k && lline[i + k - 1][j + k - 1] >= k) {
                            res = max(k, res);
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << res;

    return 0;
}