#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

ll a[1003], sa[1000006];
ll b[1003], sb[1000006];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll t, n, m;
    cin >> t;

    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        a[i] = a[i - 1] + tmp;
    }

    int idx_a = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            sa[idx_a++] = a[i] - a[j];
        }
    }
    sort(sa, sa + idx_a);

    cin >> m;
    b[0] = 0;
    for (int i = 1; i <= m; i++) {
        ll tmp;
        cin >> tmp;
        b[i] = b[i - 1] + tmp;
    }

    int idx_b = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            sb[idx_b++] = b[i] - b[j];
        }
    }
    sort(sb, sb + idx_b);

    ll cnt = 0;
    for (int i = 0; i < idx_b; i++) {
        int lb = lower_bound(sa, sa + idx_a, t - sb[i]) - sa;
        int ub = upper_bound(sa, sa + idx_a, t - sb[i]) - sa;

        cnt += ub - lb;
    }

    cout << cnt;

    return 0;
}