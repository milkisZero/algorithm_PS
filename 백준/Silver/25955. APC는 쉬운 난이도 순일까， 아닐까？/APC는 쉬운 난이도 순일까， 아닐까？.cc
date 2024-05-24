#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

map<char, ll> mp;

bool cmp(string a, string b) {
    if (mp[a[0]] == mp[b[0]]) {
        string a1 = a.substr(1, a.length());
        string b1 = b.substr(1, a.length());
        return stoll(a1) > stoll(b1);
    }

    return mp[a[0]] < mp[b[0]];
}

int main() {
    fastio;

    ll n;
    cin >> n;
    vector<string> v(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s[i] = v[i];
    }

    mp['B'] = 0;
    mp['S'] = 1;
    mp['G'] = 2;
    mp['P'] = 3;
    mp['D'] = 4;

    sort(v.begin(), v.end(), cmp);

    vector<string> res;
    for (int i = 0; i < n; i++) {
        if (s[i] != v[i]) res.push_back(v[i]);
    }

    if (res.empty()) cout << "OK";
    else {
        cout << "KO\n";
        for (auto e : res) cout << e << ' ';
    }
    return 0;
}