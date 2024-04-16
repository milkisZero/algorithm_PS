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
    ll r = 31, m = 1234567891;
    ll n, b = 1, sum = 0;
    cin >> n;

    char a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += (b * (int)(a - 'a' + 1)) % m;
        b *= r;
        b %= m;
    }
    cout << sum;

    return 0;
}