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

    ll n;
    cin >> n;

    string s;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        istringstream iss(s);

        vector<string> v;
        string a;
        while (getline(iss, a, ' ')) {
            v.push_back(a);
        }

        cout << "Case #" << i << ": ";
        for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';
        cout << '\n';
    }

    return 0;
}