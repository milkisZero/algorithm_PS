// #bs #lb #apc_2023
// #include <iostream>
// using namespace std;

// long long a, d, x;

// long long lb() {
//     long long l = 1, r = x, m;
//     while (l < r) {
//         m = (r + l) / 2;

//         if (m * a + m * (m - 1) / 2 * d < x)
//             l = m + 1;
//         else
//             // lb : 중간값이 원하는 값보다 크거나 같을 경우
//             // ub : 중간값이 원하는 값보다 큰 경우
//             r = m;
//     }

//     return r;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         cin >> a >> d >> x;

//         long long floor = lb();
//         long long floor2 = floor - 1;
//         long long cnt = x - (floor2 * a + floor2 * (floor2 - 1) / 2 * d);

//         cout << floor << ' ' << cnt << '\n';
//     }

//     return 0;
// }

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

    ll q;
    cin >> q;

    while (q--) {
        ll a, d, x;
        cin >> a >> d >> x;

        ll A = d, B = 2 * a - d, C = -2 * x;
        double k = (-B + sqrt(B * B - 4 * C * A)) / (2 * A);

        ll tmp;
        if (k == (ll)k) tmp = k;
        else tmp = ceil(k);

        ll k2 = tmp - 1;
        k2 = k2 * a + k2 * (k2 - 1) * d / 2;

        cout << tmp << ' ' << x - k2 << '\n';
    }

    return 0;
}