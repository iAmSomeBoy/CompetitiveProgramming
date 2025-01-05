#include<stdio.h>

int main() {
    int t, n; // Number of test cases and input value
    scanf("%d", &t); // Read number of test cases
    
    while(t--) {
        scanf("%d", &n); // Read the value of n
        int count = 0;

        for (int b = 1; b < n; b++) {
            int a = n - b;
            if (a > 0 && a < n) {
                count++;
            }
        }

        printf("%d\n", count); // Output result for this test case
    }
    return 0;
}
