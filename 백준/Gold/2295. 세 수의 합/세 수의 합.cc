#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<int> v2;

int main() {
    fastio;

    int n;
    cin >> n;

    int v[n];
    for (auto &e : v) cin >> e;
    sort(v, v + n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v2.push_back(v[i] + v[j]);
        }
    }
    sort(v2.begin(), v2.end());

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            ll k = v[i] - v[j];

            if (binary_search(v2.begin(), v2.end(), k)) {
                cout << v[i];
                return 0;
            }
        }
    }

    return 0;
}