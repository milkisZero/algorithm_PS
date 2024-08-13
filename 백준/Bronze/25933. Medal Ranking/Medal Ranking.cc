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

    int n;
    cin >> n;
    while (n--) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        bool count = 0, color = 0;
        if (a + b + c > d + e + f) count = 1;
        if (a > d) color = 1;
        else if (a == d) {
            if (b > e) color = 1;
            else if (b == e) {
                if (c > f) color = 1;
            }
        }

        cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
        if (count && color) cout << "both\n";
        else if (count) cout << "count\n";
        else if (color) cout << "color\n";
        else cout << "none\n";
        cout << '\n';
    }

    return 0;
}