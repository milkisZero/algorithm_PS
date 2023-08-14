#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int res;
    if (s3 != "FizzBuzz" && s3 != "Fizz" && s3 != "Buzz") {
        res = stoi(s3) + 1;
    }
    if (s1 != "FizzBuzz" && s1 != "Fizz" && s1 != "Buzz") {
        res = stoi(s1) + 3;
    }
    if (s2 != "FizzBuzz" && s2 != "Fizz" && s2 != "Buzz") {
        res = stoi(s2) + 2;
    }

    if (res % 3 == 0 && res % 5 == 0)
        cout << "FizzBuzz";
    else if (res % 3 == 0)
        cout << "Fizz";
    else if (res % 5 == 0)
        cout << "Buzz";
    else
        cout << res;

    return 0;
}