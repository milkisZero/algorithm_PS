#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll ccw(pll a, pll b, pll c) {
    auto [af, as] = a;
    auto [bf, bs] = b;
    auto [cf, cs] = c;
    return (bf - af) * (cs - as) - (bs - as) * (cf - af);
}

bool intersect(pll a, pll b, pll ex1, pll ex2) {
    ll res1, res2;
    res1 = ccw(a, b, ex1) * ccw(a, b, ex2), res2 = ccw(ex1, ex2, a) * ccw(ex1, ex2, b);
    if (res1 <= 0 && res2 <= 0) {
        if (!res1 && !res2) {
            pll p1 = max(a, b), p2 = min(a, b);
            pll p3 = max(ex1, ex2), p4 = min(ex1, ex2);
            if (p1 >= p4 && p3 >= p2) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool isIn(pll a, pll ex1, pll ex2, pll ex3) {
    if (a.second <= ex1.second && a.second >= ex2.second && ex1.first <= a.first && ex3.first >= a.first) {
        return true;
    }
    return false;
}

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;

        ll p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;
        ll leftX = min(p1, p3), rightX = max(p1, p3);
        ll botY = min(p2, p4), topY = max(p2, p4);

        pll a = {ax, ay}, b = {bx, by};
        pll ex1 = {leftX, topY}, ex2 = {leftX, botY};
        pll ex3 = {rightX, topY}, ex4 = {rightX, botY};

        if (intersect(a, b, ex1, ex2) || intersect(a, b, ex3, ex4) || intersect(a, b, ex1, ex3) || intersect(a, b, ex2, ex4)) cout << "T" << endl;
        else if (isIn(a, ex1, ex2, ex3) && isIn(b, ex1, ex2, ex3)) cout << "T" << endl;
        else cout << "F" << endl;
    }

    return 0;
}