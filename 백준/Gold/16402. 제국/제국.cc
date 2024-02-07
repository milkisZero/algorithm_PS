#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

map<string, int> mm;
int par[505];
string s[505];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
}

int find(int a) {
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b) {
    if (find(a) != find(b))
        par[find(a)] = find(b);
    else {
        par[b] = b;
        par[find(a)] = b;
    }
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    init(n);

    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
        mm.insert({s[i], i});
    }
    for (int i = 0; i < m; i++) {
        string a;
        getline(cin, a);

        string buf[3];
        istringstream ss(a);
        for (int j = 0; getline(ss, buf[j], ','); j++) {
        }

        if (buf[2] == "1")
            uni(mm[buf[1]], mm[buf[0]]);
        else
            uni(mm[buf[0]], mm[buf[1]]);
    }

    int cnt = 0;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        if (par[i] == i) {
            cnt++;
            v.push_back(s[i]);
        }
    }

    sort(v.begin(), v.end());

    cout << cnt << '\n';
    for (auto e : v) {
        cout << e << '\n';
    }

    return 0;
}