#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

bool arr[1000006];

int main() {
    fastio;

    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    for (ll i = 2; i <= sqrt(b); i++) {
        for (ll j = a / (i * i); j * i * i <= b; j++) {
            if (j * i * i >= a)
                arr[j * i * i - a] = 1;
        }
    }

    ll cnt = 0;
    for (ll i = a; i <= b; i++) {
        if (!arr[i - a]) cnt++;
    }

    cout << cnt;

    return 0;
}