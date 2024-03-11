#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <map>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    for (int T = 0; T < 3; T++) {
        ll n;
        cin >> n;

        ll sum = 0;
        pll coin[103];
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            coin[i] = {a, b};
            sum += a * b;
        }

        if (sum % 2) {
            cout << 0 << '\n';
            continue;
        }

        ll check[50005] = {0};
        for (int j = 0; j < n; j++) {
            for (int i = sum / 2; i >= 0; i--) {
                if (coin[j].first > i)
                    break;
                else if (check[i])
                    continue;

                for (int k = 1; k <= coin[j].second; k++) {
                    ll tmp = coin[j].first * k;
                    if (tmp > i)
                        break;
                    if (tmp + check[i - tmp] == i)
                        check[i] = i;
                }
            }
            if (check[sum / 2])
                break;
        }

        if (check[sum / 2])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}