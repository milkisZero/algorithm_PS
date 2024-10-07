
#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[1003];

int main() {
    fastio;

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i <= 10000; i++) {
        ll cnt = 0, cnt2 = 0, cnt3 = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] > i) cnt++;
            else if (arr[j] == i) cnt2++;
            else cnt3++;
            // if (arr[i] >= i) cnt++;
            // if (arr[i] <= i) cnt2++;
        }

        // if (cnt == i && cnt2 == n-i) {
        //     cout << i << '\n';
        //     return 0;
        //  }

        if (cnt == i) {
            cout << i << endl;
            return 0;
        }
        else if (cnt < i && cnt + cnt2 >= i) {
            cout << i << endl;
            return 0;
        }

        // if (cnt + cnt2 < i) continue;
        // if (cnt < i) {
        //     cnt2 -= (i - cnt);
        //     cnt += (i - cnt);
        // }

        // if (cnt3 + cnt2 > i) continue;

        // cout << cnt << cnt2 << cnt3 << '\n';

        // if (cnt >= i && (cnt2 + cnt3) <= i) {
        //     cout << i << '\n';
        //     return 0;
        // }
    }

    return 0;
}