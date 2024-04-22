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
        string s;
        cin >> s;
        int k = 0;
        for (int i = 0; i < 3; i++) {
            k += pow(26, 2 - i) * (s[i] - 'A');
        }
        string a = s.substr(4, 4);
        if (abs(k - stoi(a)) <= 100) cout << "nice";
        else cout << "not nice";
        cout << '\n';
    }

    return 0;
}