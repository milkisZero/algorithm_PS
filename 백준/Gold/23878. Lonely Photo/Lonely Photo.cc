#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
string s;
ll n;

ll count(char c) {
    queue<ll> q;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c)
            q.push(i);
    }

    ll cnt = 0, prev = 0;
    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        ll ep;
        if (q.empty())
            ep = n - 1;
        else
            ep = q.front() - 1;

        if (cur - prev >= 2)
            cnt += cur - prev - 1;
        if (ep - cur >= 2)
            cnt += ep - cur - 1;
        cnt += (cur - prev) * (ep - cur);

        prev = cur + 1;
    }
    return cnt;
}

int main() {
    fastio;

    cin >> n;
    cin >> s;

    cout << count('H') + count('G') << '\n';

    return 0;
}