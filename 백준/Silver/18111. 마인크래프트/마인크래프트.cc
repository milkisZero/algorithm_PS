#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[505][505];

int main() {
    fastio;

    ll n, m, b;
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    ll t = LLINF, h = -1;
    for (ll k = 0; k <= 256; k++) {
        ll time = 0, cnt = b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll tmp = abs(arr[i][j] - k);
                if (arr[i][j] < k) {
                    cnt -= tmp;
                    time += tmp;
                }
                if (arr[i][j] > k) {
                    cnt += tmp;
                    time += 2 * tmp;
                }
            }
        }

        if (cnt >= 0) {
            if (time <= t) {
                t = time;
                h = k;
            }
        }
    }

    cout << t << ' ' << h;

    return 0;
}