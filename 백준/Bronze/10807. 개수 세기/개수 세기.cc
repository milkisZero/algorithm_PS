#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[205];

int main() {
    fastio;

    ll n, k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        arr[100 + k]++;
    }

    cin >> k;
    cout << arr[100 + k];

    return 0;
}