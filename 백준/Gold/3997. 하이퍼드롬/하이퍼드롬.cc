#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll acnt[300005];

unordered_map<ll, ll> mp1, mp2;

int main() {
    fastio;

    ll n;
    cin >> n;

    string s;
    cin >> s;
    s = " " + s;

    ll res = 0;
    for (int i = 1; i <= n; i++) {

        ll k;
        if (s[i] >= 'a') k = s[i] - 'a' + 26;
        else k = s[i] - 'A';

        k = 1ll << k;

        // 1 ^ 1 -> 0
        if (acnt[i - 1] & k) acnt[i] = acnt[i - 1] & ~k;
        // 0 ^ 1 -> 1
        else acnt[i] = acnt[i - 1] | k;

        if (i % 2) {
            // 홀 - 짝
            for (int j = 0; j < 52; j++) {
                ll k = 1ll << j;
                if (mp2.find(acnt[i] ^ k) != mp2.end())
                    res += mp2[acnt[i] ^ k];
            }

            // 홀 - 홀
            if (mp1.find(acnt[i]) != mp1.end()) res += mp1[acnt[i]];

            ll bitcnt = 0;
            for (int j = 0; j < 52; j++) {
                if (acnt[i] & (1ll << j)) {
                    bitcnt++;
                    if (bitcnt > 1) break;
                }
            }
            if (bitcnt == 1) res++;
            mp1[acnt[i]]++;
        }
        else {
            // 짝 - 홀
            for (int j = 0; j < 52; j++) {
                ll k = 1ll << j;
                if (mp1.find(acnt[i] ^ k) != mp1.end())
                    res += mp1[acnt[i] ^ k];
            }

            // 짝 - 짝
            if (mp2.find(acnt[i]) != mp2.end()) res += mp2[acnt[i]];

            if (acnt[i] == 0) res++;
            mp2[acnt[i]]++;
        }
    }

    cout << res;

    return 0;
}