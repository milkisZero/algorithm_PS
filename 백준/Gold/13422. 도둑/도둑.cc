#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> vec(n + 1);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        long long cnt = vec[0], res = 0;
        for (int i = 0, j = 0; i < n;) {

            if (j - i + 1 == m && cnt < k)
                res++;
            if (j - i + 1 < m) {
                cnt += vec[(++j) % n];
            }
            else {
                if ((j + 1) % n == i)
                    break;
                cnt -= vec[i];
                i++;
            }
        }

        cout << res << '\n';
    }

    return 0;
}