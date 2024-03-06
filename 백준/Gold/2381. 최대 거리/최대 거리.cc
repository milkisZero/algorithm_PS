// #수학 #애드혹
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

    int n;
    cin >> n;

    int p_maxi = -INF + 1, p_mini = INF;
    int m_maxi = -INF + 1, m_mini = INF;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        p_maxi = max(p_maxi, (a + b));
        p_mini = min(p_mini, (a + b));
        m_maxi = max(m_maxi, (a - b));
        m_mini = min(m_mini, (a - b));
    }

    cout << max(abs(p_maxi - p_mini), abs(m_maxi - m_mini));

    return 0;
}