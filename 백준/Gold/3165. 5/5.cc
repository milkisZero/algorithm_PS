#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll res = LLINF, n, k;
string s;
ll chk[20];

void recur(string a, ll start, ll kcnt) {
    if (kcnt == k) {
        ll c = stoll(a);
        ll mini = LLINF;
        if (n < c) mini = min(mini, c);

        for (int i = 0; i < s.length(); i++) {
            ll tmp = round(pow(10, i));
            if (chk[s.length() - 1 - i] == 0 && n < c + tmp) {
                if (s[s.length() - 1 - i] == '9' && s.length() - 2 - i >= 0 && chk[s.length() - 2 - i])
                    continue;
                mini = min(mini, c + tmp);
            }
        }
        ll tmp = round(pow(10, s.length()));
        if (n < c + tmp) mini = min(mini, c + tmp);

        string p = to_string(mini);
        ll idx = s.length();
        for (int i = 0; i < s.length(); i++) {
            if (p[i] > s[i]) {
                idx = i;
                break;
            }
        }
        for (int i = idx + 1; i < s.length(); i++) {
            if (chk[i] == 0) p[i] = '0';
        }

        res = min(res, stoll(p));
        return;
    }
    else if (start == s.length()) return;

    string b = a;
    for (int i = start; i < s.length(); i++) {
        b[i] = '5';
        chk[i] = 1;
        recur(b, i + 1, kcnt + 1);

        b[i] = s[i];
        chk[i] = 0;
        recur(b, i + 1, kcnt);
    }
}

int main() {
    fastio;

    cin >> s >> k;

    if (s.length() < k) {
        for (int i = 0; i < k; i++) cout << '5';
        return 0;
    }

    n = stoll(s);
    recur(s, 0, 0);

    cout << res;

    return 0;
}