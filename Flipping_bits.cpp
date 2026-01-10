#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while (q--) {
        unsigned int n;
        cin >> n;
        unsigned int ans = ~n;
        ans = ans & 0xFFFFFFFF; // Ensure only 32 bits are considered
        cout << ans << endl;
    }
    return 0;
}