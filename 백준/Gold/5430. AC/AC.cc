#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string op, a;
        int n = 0;
        cin >> op >> n >> a;

        deque<int> dq;
        string num = "";
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '[' || a[i] == ']')
                continue;

            if (a[i] == ',') {
                dq.push_back(stoi(num));
                num = "";
            }
            else
                num = num + a[i];
        }
        if (!num.empty())
            dq.push_back(stoi(num));

        int err = 0, rev = 0;
        for (int i = 0; i < op.length(); i++) {
            switch (op[i]) {
            case 'R':
                rev = rev == 0 ? 1 : 0;
                break;
            default:
                if (dq.empty())
                    err = 1;
                else if (!rev)
                    dq.pop_front();
                else
                    dq.pop_back();
            }

            if (err)
                break;
        }

        if (err)
            cout << "error" << '\n';
        else {
            if (rev) {
                cout << '[';
                for (int i = dq.size() - 1; i >= 0; i--) {
                    cout << dq[i];
                    if (i - 1 >= 0)
                        cout << ',';
                }
                cout << ']' << '\n';
            }
            else {
                cout << '[';
                for (int i = 0; i < dq.size(); i++) {
                    cout << dq[i];
                    if (i + 1 < dq.size())
                        cout << ',';
                }
                cout << ']' << '\n';
            }
        }
    }

    return 0;
}