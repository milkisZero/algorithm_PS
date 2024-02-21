#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    int n;
    cin >> n;

    int q = 0;
    while (n--) {
        string s;
        int x;
        cin >> s;

        if (s == "add") {
            cin >> x;
            q |= 1 << x;
        }
        else if (s == "remove") {
            cin >> x;
            q &= ~(1 << x);
        }
        else if (s == "check") {
            cin >> x;
            if ((q & 1 << x) == 0)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
        else if (s == "toggle") {
            cin >> x;
            if ((q & 1 << x) == 0)
                q |= 1 << x;
            else
                q &= ~(1 << x);
        }
        else if (s == "all") {
            q |= (1 << 21) - 1;
        }
        else {
            q &= 0;
        }
    }

    return 0;
}