#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            long long tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        long long res = 0;
        while (pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();

            pq.push(a + b);
            res += a + b;
        }
        pq.pop();

        cout << res << '\n';
    }

    return 0;
}