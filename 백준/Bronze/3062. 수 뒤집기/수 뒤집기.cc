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

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = stoi(s);
        reverse(s.begin(), s.end());
        n += stoi(s);

        string res1, res2;
        res1 = res2 = to_string(n);
        reverse(res2.begin(), res2.end());

        if (res1 == res2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}