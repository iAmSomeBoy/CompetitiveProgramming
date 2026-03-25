#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);  
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        sort(b.begin(), b.end()); 
        
        int count = 1;
        int last = b[0];  
        
        for (int i = 1; i < n; i++) { 
            if (b[i] > last) {
                count++;
                last = b[i];
            }
        }
        cout << count << endl;
    }
    return 0;
}