#include <iostream>
#include <vector>
using namespace std;

vector<int> stk;
vector<int> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < n; i++) {
        int tmp = vec.back();
        vec.pop_back();

        int check = 0;
        for (int j = stk.size() - 1; j >= 0; j--) {
            if (tmp < stk[j]) {
                res.push_back(stk[j]);
                check = 1;
                break;
            }   
            else
                stk.pop_back();
        }

        if (check == 0)
            res.push_back(-1);

        stk.push_back(tmp);
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << ' ';
    }

    return 0;
}