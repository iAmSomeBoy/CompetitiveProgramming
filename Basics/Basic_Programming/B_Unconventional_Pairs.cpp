#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        int max_diff = 0;
        for (int i = 0; i < n; i += 2) {
            int diff = a[i + 1] - a[i];
            if (diff > max_diff) {
                max_diff = diff;
            }
        }
        
        cout << max_diff << endl;
    }
    return 0;
}