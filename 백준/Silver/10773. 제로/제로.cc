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

    int n;
    cin >> n;
    stack<int> stk;
    while (n--) {
        int x;
        cin >> x;
        if (!x) stk.pop();
        else stk.push(x);
    }

    int k = 0;
    while (!stk.empty()) {
        k += stk.top();
        stk.pop();
    }

    cout << k;

    return 0;
}