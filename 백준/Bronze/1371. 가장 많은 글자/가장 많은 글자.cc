#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
int alp[28];

int main() {
    fastio;

    string s;
    int maxi = -1;
    while (getline(cin, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                alp[s[i] - 'a']++;
            maxi = max(maxi, alp[s[i] - 'a']);
        }
    }

    for (int i = 0; i < 28; i++) {
        if (maxi == alp[i])
            cout << char(i + 'a');
    }

    return 0;
}