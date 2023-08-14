#include <iostream>
using namespace std;
int s1, s3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        s1 += i;
        s3 += i * i * i;
    }

    cout << s1 << '\n';
    cout << s1 * s1 << '\n';
    cout << s3 << '\n';

    return 0;
}