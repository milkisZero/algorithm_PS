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

        ll sum = 0, a, b;
        pll coin[103];
        ll check[50005] = {0};
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            coin[i] = {a, b};
            sum += a * b;
        }

        if (sum % 2) {
            cout << 0 << '\n';
            continue;
        }

        for (int j = 0; j < n; j++) {
            auto [cost, cnt] = coin[j];
            for (int i = sum / 2; i > cost; i--) {
                if (!check[i]) {
                    for (int k = 1; k <= cnt && cost * k < i; k++) {
                        ll tmp = cost * k;
                        check[tmp] = 1;
                        if (check[i - tmp])
                            check[i] = 1;
                    }
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