#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        string a, b;
        iss >> a >> b;

        int n = stoi(b);
        int i = 0;
        do {
            if (++i == n) {
                cout << s << " = " << a << '\n';
                break;
            }
        } while (next_permutation(a.begin(), a.end()));
        if (i != n)
            cout << s << " = No permutation" << '\n';
    }

    return 0;
}