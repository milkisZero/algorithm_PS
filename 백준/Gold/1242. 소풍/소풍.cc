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

    ll n, k, m;
    cin >> n >> k >> m;

    ll res = 0;
    while (n && m) {
        res++;
        m -= k;
        if (m < 0) {
            if (n > k)
                m = n + m;
            else
                m = (n - (k % n) + m + k) % n;
        }
        n--;
    }

    cout << res;

    return 0;
}