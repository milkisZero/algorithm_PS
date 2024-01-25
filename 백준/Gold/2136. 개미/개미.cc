#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

pll arr[100006];

int cmp(pll a, pll b) {
    return abs(a.first) < abs(b.first);
}

int main() {
    fastio();

    ll n, l;
    cin >> n >> l;

    ll pcnt = 0, mcnt = 0;
    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        arr[i] = {tmp, i};
        tmp > 0 ? pcnt++ : mcnt++;
    }

    sort(arr + 1, arr + n + 1, cmp);

    ll minus = 0, plus = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i].first > 0 && plus == 0)
            plus = l - arr[i].first;
        if (arr[i].first < 0)
            minus = -arr[i].first;
    }

    if (plus > minus)
        cout << arr[n - pcnt + 1].second << ' ' << plus;
    else
        cout << arr[mcnt].second << ' ' << minus;

    return 0;
}