#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

string s, k;
int res = -1;

void recur(string a, int n) {
    if (a.length() == s.length()) {
        if (stoi(a) < stoi(k))
            res = max(res, stoi(a));
        else
            return;
    }

    for (int i = 0; i < s.length(); i++) {
        string b = "";
        if ((n & (1 << i)) == 0) {
            if (a == "" && s[i] == '0')
                continue;
            b = a + s[i];
            recur(b, (n | (1 << i)));
        }
    }
}

int main() {
    fastio;

    cin >> s >> k;

    if (s.length() > k.length()) {
        cout << -1;
        return 0;
    }
    else if (s.length() < k.length()) {
        sort(s.begin(), s.end(), greater<>());
        cout << s;
        return 0;
    }

    recur("", 0);

    cout << res;

    return 0;
}