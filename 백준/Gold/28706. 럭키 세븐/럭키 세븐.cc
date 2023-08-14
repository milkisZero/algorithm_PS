#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int dp[7] = {0};
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            char op1, op2;
            int num1, num2;
            cin >> op1 >> num1;
            cin >> op2 >> num2;

            int arr[7] = {0};
            for (int j = 0; j < 7; j++) {
                if (dp[j] == 0)
                    continue;

                int tmp;
                if (op1 == '+')
                    tmp = j + num1;
                else
                    tmp = j * num1;
                arr[tmp % 7] = 1;

                if (op2 == '+')
                    tmp = j + num2;
                else
                    tmp = j * num2;
                arr[tmp % 7] = 1;
            }

            for (int j = 0; j < 7; j++) {
                dp[j] = arr[j];
            }
        }

        if (dp[0])
            cout << "LUCKY" << '\n';
        else
            cout << "UNLUCKY" << '\n';
    }

    return 0;
}