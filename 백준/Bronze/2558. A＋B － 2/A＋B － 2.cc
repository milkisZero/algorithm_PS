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

pi arr[103];
int dp[103][5003];

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    cout << n + k;

    return 0;
}