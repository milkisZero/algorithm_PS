#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int r;
    do {
        r = a % b;
        a = b, b = r;
    } while (r);
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        cout << (a * b) / gcd(a, b) << '\n';
    }

    return 0;
}
