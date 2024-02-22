#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    ll a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);
    a--;

    cout << b * (b + 1) / 2 - a * (a + 1) / 2;

    return 0;
}