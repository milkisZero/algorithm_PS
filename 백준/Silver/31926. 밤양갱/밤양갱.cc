#include <bits/stdc++.h>
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
    fastio;

    ll n;
    cin >> n;
    ll tmp = 8;

    ll cnt = 1;
    ll time = 0;

    while (cnt <= n) {
        if (cnt * 2 <= n) {
            cnt *= 2;
            time++;
        }
        else {
            time++;
            break;
        }
    }

    cout << tmp + time + 1;

    return 0;
}