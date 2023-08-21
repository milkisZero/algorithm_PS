#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int tmp;
        if (s == "push_front") {

            cin >> tmp;
            dq.push_front(tmp);
        }
        else if (s == "push_back") {
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if (s == "pop_front") {
            if (dq.empty())
                cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (s == "pop_back") {
            if (dq.empty())
                cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (s == "size") {
            cout << dq.size() << '\n';
        }
        else if (s == "empty") {
            cout << dq.empty() << '\n';
        }
        else if (s == "front") {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
        }
        else if (s == "back") {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
        }
    }

    return 0;
}
