#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int alp[27];

int main() {
    fastio;

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        alp[s[i] - 'A']++;
    }

    int cnt = 0, c;
    string res = "";
    for (int i = 0; i < 27; i++) {
        if (alp[i] % 2) {
            cnt++;
            c = i;
        }
        alp[i] /= 2;
        while (alp[i]--) {
            res = res + char(i + 'A');
        }

        if (cnt > 1)
            break;
    }

    if (cnt > 1)
        cout << "I'm Sorry Hansoo\n";
    else {
        cout << res;
        if (cnt)
            cout << char(c + 'A');
        reverse(res.begin(), res.end());
        cout << res;
    }

    return 0;
}