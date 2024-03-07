#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll arr[1000006];
ll a1[1000006], a2[1000006];
ll a3[1000006], a4[1000006];

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    a2[0] = a4[n + 1] = INF;
    for (int i = 1; i <= n; i++) {
        if (a2[i - 1] > arr[i]) {
            a1[i] = a2[i] = arr[i];
        }
        else {
            a2[i] = a2[i - 1];
            a1[i] = max(arr[i], a1[i - 1]);
        }

        if (a3[n + 1 - i + 1] < arr[n + 1 - i]) {
            a3[n + 1 - i] = a4[n + 1 - i] = arr[n + 1 - i];
        }
        else {
            a3[n + 1 - i] = a3[n + 1 - i + 1];
            a4[n + 1 - i] = min(arr[n + 1 - i], a4[n + 1 - i + 1]);
        }
    }

    ll res = -INF;
    for (int i = 1; i <= n - 2; i++) {
        res = max(res, a1[i] - a2[i - 1] + a3[i + 2] - a4[i + 1]);
    }

    cout << res;

    return 0;
}