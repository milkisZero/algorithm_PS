#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int cnt(ll n) {
    if (n == 0) return 0;
    return (n % 10 == 5) + cnt(n / 10);
}

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;
    n++;

    ll tmp = 1;
    while (1) {
        if (cnt(n) >= k) break;
        while ((n / tmp) % 10 == 5) tmp *= 10;
        n += tmp;
    }
    cout << n;

    return 0;
}