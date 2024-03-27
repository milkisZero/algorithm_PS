#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[100005];
ll check[1000005];
ll point[1000005];

int main() {
    fastio;

    ll n, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        check[arr[i]] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; arr[i] * j < 1000005; j++) {
            point[arr[i] * j]--;
            if (check[arr[i] * j])
                point[arr[i]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << point[arr[i]] << ' ';
    }

    return 0;
}