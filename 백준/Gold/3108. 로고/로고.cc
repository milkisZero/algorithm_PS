#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

map<int, vector<pi>> m;
map<pi, pi> par;

pi find(pi a) {
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void uni(pi a, pi b) {
    if (a.first > b.first)
        swap(a, b);
    else if (a.second > b.second)
        swap(a, b);

    if (find(a) != find(b))
        par[find(a)] = find(b);
}

int main() {
    fastio();

    int n;
    cin >> n;

    int cnt = 0, check = 1, idx = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        par[{a, b}] = {a, b};
        par[{c, d}] = {c, d};
        par[{a, d}] = {a, d};
        par[{c, b}] = {c, b};

        m[idx].push_back({a, b});
        m[idx].push_back({c, d});
        m[idx].push_back({a, d});
        m[idx++].push_back({c, b});

        if (check && ((!a && (b <= 0 && d >= 0)) || (!c && (b <= 0 && d >= 0)))) {
            cnt--;
            check = 0;
        }
        else if (check && ((!b && (a <= 0 && c >= 0)) || (!d && (a <= 0 && c >= 0)))) {
            cnt--;
            check = 0;
        }
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        int s = iter->first;
        for (int i = 0; i < m[s].size(); i++) {
            uni(m[s][0], m[s][i]);
        }
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        int s = iter->first;
        // 세로, 가로
        pair<pi, pi> a1, a2, b1, b2;
        a1 = {m[s][0], m[s][2]};
        a2 = {m[s][3], m[s][1]};
        b1 = {m[s][0], m[s][3]};
        b2 = {m[s][2], m[s][1]};

        for (auto iter2 = m.begin(); iter2 != m.end(); iter2++) {
            int e = iter2->first;
            pair<pi, pi> a3, a4, b3, b4;
            a3 = {m[e][0], m[e][2]};
            a4 = {m[e][3], m[e][1]};
            b3 = {m[e][0], m[e][3]};
            b4 = {m[e][2], m[e][1]};

            if (a1.first.first >= b3.first.first && a1.first.first <= b3.second.first) {
                if (b3.first.second >= a1.first.second && b3.first.second <= a1.second.second)
                    uni(a1.first, b3.first);
                if (b4.first.second >= a1.first.second && b4.first.second <= a1.second.second)
                    uni(a1.first, b4.first);
            }
            if (a2.first.first >= b3.first.first && a2.first.first <= b3.second.first) {
                if (b3.first.second >= a2.first.second && b3.first.second <= a2.second.second)
                    uni(a2.first, b3.first);
                if (b4.first.second >= a2.first.second && b4.first.second <= a2.second.second)
                    uni(a2.first, b4.first);
            }
            if (a3.first.first >= b1.first.first && a3.first.first <= b1.second.first) {
                if (b1.first.second >= a3.first.second && b1.first.second <= a3.second.second)
                    uni(a3.first, b1.first);
                if (b2.first.second >= a3.first.second && b2.first.second <= a3.second.second)
                    uni(a3.first, b2.first);
            }
            if (a4.first.first >= b1.first.first && a4.first.first <= b1.second.first) {
                if (b1.first.second >= a4.first.second && b1.first.second <= a4.second.second)
                    uni(a4.first, b1.first);
                if (b2.first.second >= a4.first.second && b2.first.second <= a4.second.second)
                    uni(a4.first, b2.first);
            }
        }
    }

    for (auto iter = par.begin(); iter != par.end(); iter++) {
        pi s = iter->first;
        if (s == par[s]) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}