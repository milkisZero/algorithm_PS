#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll n;
    cin >> n;
    vector<ll> v(n + 1);

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    v[n] = 0;

    ll cur = 0, k = 0;
    char prev;
    while (sum--) {
        if (prev == 'R' && v[cur] == 0) k = !k;
        else if (prev == 'L') {
            if (cur >= 1 && v[cur - 1] == 1 && v[cur] > 0) k = !k;
            else if (cur == 0 && v[cur] > 0) k = !k;
        }

        if (k == 0) {
            cout << 'R';
            v[cur]--;
            cur++;
            prev = 'R';
        }
        else {
            cout << 'L';
            cur--;
            v[cur]--;
            prev = 'L';
        }
    }

    return 0;
}