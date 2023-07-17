#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    string res = "";
    for (int i = 0; i < n; i++) {
        string tmp = s;
        tmp.erase(i, 1);

        string a = "", b = "";
        a.append(tmp.begin(), tmp.end() - tmp.length() / 2);
        b.append(tmp.begin() + tmp.length() / 2, tmp.end());

        if (!a.compare(b)) {
            if (res.compare(a)) {
                cnt++;
                res = a;
            }
        }
    }

    if (n % 2 == 0)
        cnt = 0;

    if (cnt == 1)
        cout << res << '\n';
    else if (cnt > 1)
        cout << "NOT UNIQUE" << '\n';
    else
        cout << "NOT POSSIBLE" << '\n';

    return 0;
}