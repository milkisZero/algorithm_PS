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

    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);

        map<char, int> mp;
        for (char c = 'A'; c <= 'Z'; c++) mp[c] = 0;

        for (auto e : s) {
            if (!(('a' <= e && e <= 'z') || ('A' <= e && e <= 'Z'))) continue;
            if (e >= 'a') e -= 'a' - 'A';
            mp[e]++;
        }

        int mini = INF;
        for (auto [k, v] : mp) mini = min(mini, v);

        cout << "Case " << i << ": ";
        if (mini == 1) cout << "Pangram!\n";
        else if (mini == 2) cout << "Double pangram!!\n";
        else if (mini == 3) cout << "Triple pangram!!!\n";
        else cout << "Not a pangram\n";
    }

    return 0;
}