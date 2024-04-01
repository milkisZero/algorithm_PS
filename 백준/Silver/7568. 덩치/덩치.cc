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

    int n, a, b;
    cin >> n;
    pi arr[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = {a, b};
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        auto [w, h] = arr[i];
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            auto [w1, h1] = arr[j];
            if (w < w1 && h < h1)
                cnt++;
        }
        cout << cnt + 1 << ' ';
    }

    return 0;
}