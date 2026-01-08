#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0) {          // i is prime
            for (int j = i; j <= n; j += i) {
                cnt[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 2)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
