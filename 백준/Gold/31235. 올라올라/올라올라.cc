#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll n;
    cin >> n;

    ll idx = 0, res = -1;
    ll prev = 0;
    for (int i = 0; i <= n; i++) {
        ll tmp;
        if (i < n)
            cin >> tmp;
        else
            tmp = INF;
        if (i == 0)
            prev = tmp;
        else if (prev <= tmp) {
            res = max(i - idx, res);
            idx = i;
            prev = tmp;
        }
    }

    cout << res;

    return 0;
}