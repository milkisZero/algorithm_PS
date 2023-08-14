#include <iostream>
#include <set>
using namespace std;

set<int> dp[200006];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        dp[0].insert(1);
        for (int i = 1; i <= n; i++) {
            char op1, op2;
            int num1, num2;
            cin >> op1 >> num1;
            cin >> op2 >> num2;

            for (auto j = dp[i - 1].begin(); j != dp[i - 1].end(); j++) {
                int tmp;
                if (op1 == '+')
                    tmp = *j + num1;
                else
                    tmp = *j * num1;
                dp[i].insert(tmp % 7);

                if (op2 == '+')
                    tmp = *j + num2;
                else
                    tmp = *j * num2;
                dp[i].insert(tmp % 7);
            }
        }

        auto iter = dp[n].begin();
        if (*iter == 0)
            cout << "LUCKY" << '\n';
        else
            cout << "UNLUCKY" << '\n';

        for (int i = 0; i <= n; i++) {
            dp[i].clear();
        }
    }

    return 0;
}