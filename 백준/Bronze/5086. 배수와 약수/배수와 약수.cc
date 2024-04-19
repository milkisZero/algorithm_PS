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

    while (1) {
        int a, b;
        cin >> a >> b;
        if (!a && !b) break;
        if (a < b && !(b % a)) cout << "factor";
        else if (b < a && !(a % b)) cout << "multiple";
        else cout << "neither";
        cout << '\n';
    }

    return 0;
}