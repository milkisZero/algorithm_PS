#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<int> v, psum;

int main() {
    fastio;
    int n, sum = 0;
    cin >> n;

    n = pow(2, n + 1) - 1;

    v.resize(n + 1);
    psum.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        psum[i] = v[i];
    }

    for (int i = n - 1; i > 0; i -= 2)
        psum[i / 2] += max(psum[i], psum[i+1]);

    int k = max(psum[2], psum[3]);
    
    int ans = 0;

    for (int i = 2; i <= n; i++) {
        // cout << v[i/2] << endl;
        int diff = k - (v[i/2] + psum[i]);
        // cout << i <<' '<< diff << endl;
        v[i] += diff;
        if(i*2 <= n)
        {
            v[i * 2] += v[i];
            v[i * 2 + 1] += v[i];
        }
        ans += diff;
    }
    // for(int i=2; i<=n; i++)
    //     cout << v[i] << ' ';
    // cout << endl;
    cout << ans + sum;

    return 0;
}