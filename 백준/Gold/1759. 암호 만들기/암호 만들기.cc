#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<char> v;
set<string> st;
ll n, m;

void recur(string s) {
    if (s.length() == n) {
        ll cnt = 0;
        for (auto e : s) {
            if (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u') {
                cnt++;
            }
        }

        if (cnt > 0 && cnt <= n - 2)
            st.insert(s);
        return;
    }

    string k = "";
    for (auto e : v) {
        if (s[s.length() - 1] < e) {
            k = s + e;
            recur(k);
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        char a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    recur("");

    for (auto e : st) {
        cout << e << '\n';
    }

    return 0;
}