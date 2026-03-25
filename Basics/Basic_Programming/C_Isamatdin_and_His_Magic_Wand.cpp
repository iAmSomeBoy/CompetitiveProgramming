#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        bool hasEven = false, hasOdd = false;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) hasEven = true;
            else hasOdd = true;
        }
        
        // If both even and odd numbers exist, we can sort completely
        if (hasEven && hasOdd) {
            sort(a.begin(), a.end());
        }
        
        // Output the result
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}