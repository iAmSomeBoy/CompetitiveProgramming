#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;
    if (n.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    while (n.size() > 1) {
        long long sum = 0;
        for (char c : n) sum += c - '0';//sum += c - '0'; converts the character digit c (like '5') to its integer value (5) by subtracting the ASCII value of '0'.
        n = to_string(sum);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}