#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int sum[1003];

int main() {
    fastio;

    int a, b;
    cin >> a >> b;

    int idx = 1;
    for (int i = 1; idx <= b; i++) {
        for (int j = 0; j < i && idx <= b; j++) {
            sum[idx] += sum[idx - 1] + i;
            idx++;
        }
    }

    cout << sum[b] - sum[a - 1];

    return 0;
}