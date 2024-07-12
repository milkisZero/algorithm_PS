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

    string s;
    cin >> s;

    string a = "", b = "";

    string tmp;
    for (int i = 0; i < s.length(); i++) {
        tmp += s[i];

        ll k = stoll(tmp);
        string c = tmp;
        while (c.length() < s.length()) {
            k++;
            c += to_string(k);
        }

        if (s == c) {
            if (a == "") {
                a = tmp;
                b = to_string(k);
                break;
            }
        }
    }

    cout << a << ' ' << b;

    return 0;
}