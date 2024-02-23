#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<ll> v;
ll res = LLINF, point;

int bs(int a, int b, int c) {
    int l = a, r = b, m;
    while (l <= r) {
        m = (l + r) / 2;

        ll prev = b, leng = -1, cnt = 0, idx = -1;
        for (int i = v.size() - 1; i > 0; i--) {
            if (prev - v[i - 1] > m) {
                cnt++;
                leng = max(leng, prev - v[i]);
                prev = v[i];
                idx = i;
                i++;
            }
            if (cnt == c)
                break;
        }

        if (cnt < c) {
            idx = 0;
            leng = max(leng, max(v[0], prev - v[0]));
        }
        else
            leng = max(leng, prev);

        if (leng > m)
            l = m + 1;
        else
            r = m - 1;

        if (res > leng) {
            res = leng;
            point = idx;
        }
        else if (res == leng && point > idx) {
            point = idx;
        }
    }
    return -1;
}

int main() {
    fastio;

    ll l, k, c;
    cin >> l >> k >> c;

    for (int i = 0; i < k; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    bs(1, l, c);

    cout << res << ' ' << v[point];

    return 0;
}