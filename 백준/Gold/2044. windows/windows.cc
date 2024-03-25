#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int visited[103][103];
string arr[103], res[103];
map<string, vector<string>> mstr;

void find(ll a, ll b) {
    ll s = a, e = b + 1, Xcnt = 2, Ycnt = 2;
    string head = "", tail = "", key = "";

    while (arr[s][e] != '+') {
        head = head + arr[s][e];
        tail = tail + '-';
        Xcnt++;
        if ('a' <= arr[s][e] && arr[s][e] <= 'z')
            key = key + arr[s][e];
        e++;
    }
    head = '+' + head + '+';
    tail = '+' + tail + '+';
    mstr[key].push_back(head);

    s = a + 1, e = b;
    while (arr[s][e] != '+') {
        string tmp;
        for (int i = b; i < b + Xcnt; i++) {
            tmp = tmp + arr[s][i];
        }
        mstr[key].push_back(tmp);
        Ycnt++;
        s++;
    }
    mstr[key].push_back(tail);

    visited[a][b] = visited[a][b + Xcnt - 1] = visited[a + Ycnt - 1][b] = visited[a + Ycnt - 1][b + Xcnt - 1] = 1;
}

int main() {
    fastio;

    ll m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        for (int j = 0; j < n; j++) {
            res[i] = res[i] + '.';
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '+' && !visited[i][j])
                find(i, j);
        }
    }

    ll k = 0;
    for (auto [key, vec] : mstr) {
        int r = k;
        for (auto s : vec) {
            for (int i = 0; i < s.length(); i++) {
                res[r][k + i] = s[i];
            }
            r++;
        }
        k++;
        if (k >= min(n, m))
            break;
    }

    for (int i = 0; i < m; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}