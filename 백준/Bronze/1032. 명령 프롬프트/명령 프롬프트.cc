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

    int n;
    cin >> n;

    string res;
    cin >> res;

    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < res.length(); j++) {
            if (s[j] != res[j])
                res[j] = '?';
        }
    }
    cout << res;

    return 0;
}