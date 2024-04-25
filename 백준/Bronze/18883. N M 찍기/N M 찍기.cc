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
    int a, b, k = 1;
    cin >> a >> b;
    for (int j = 0; j < a; j++) {
        for (int i = 0; i < b; i++) {
            cout << k++;
            if (i != b - 1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}