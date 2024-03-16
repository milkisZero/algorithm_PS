#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 10000007

double arr[MAX];

int main() {
    fastio;

    arr[1] = 1;
    for (int i = 2; i < MAX; i++) {
        arr[i] = arr[i - 1] + log10(i);
    }

    int t, k;
    cin >> t;
    while (t--) {
        cin >> k;
        ll ans = arr[k];
        cout << ans << '\n';
    }

    return 0;
}
