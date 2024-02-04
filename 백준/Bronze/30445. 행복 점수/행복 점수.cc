#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define CV -'A'
int p[26];

int main() {
    fastio();

    p['A' CV] = 1;
    p['H' CV] = p['P' CV] = p['Y' CV] = 2;
    p['S' CV] = p['D' CV] = 3;

    string s;
    getline(cin, s);

    double pg = 0, ph = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
            continue;
        if (p[s[i] CV] == 1 || p[s[i] CV] == 2)
            ph++;
        if (p[s[i] CV] == 1 || p[s[i] CV] == 3)
            pg++;
    }

    cout << fixed;
    cout.precision(2);

    if (!pg && !ph)
        cout << "50.00";
    else if (ph == 0)
        cout << "0.00";
    else {
        double calc = ph / (pg + ph);
        int ret = calc * 100 * 1000;
        int ret2 = calc * 100 * 100;

        int tmp = ret % ret2;
        if (tmp >= 5)
            ret2++;

        cout << ret2 / 100.0;
    }

    return 0;
}