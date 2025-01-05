#include <stdio.h>

int main() {
    int a, b;

    // Input two integers a and b
    scanf("%d %d", &a, &b);

    // Calculate the missing brother
    int missing = 6 - (a + b);

    // Output the missing brother's number
    printf("%d\n", missing);

    return 0;
}
