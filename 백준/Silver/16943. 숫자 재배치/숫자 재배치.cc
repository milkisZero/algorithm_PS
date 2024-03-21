// #백트래킹
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

    sort(s.begin(), s.end());

    int res = -1;
    do {
        if (stoi(s) < stoi(k) && s[0] != '0')
            res = max(res, stoi(s));
    } while (next_permutation(s.begin(), s.end()));

    cout << res;

    return 0;
}