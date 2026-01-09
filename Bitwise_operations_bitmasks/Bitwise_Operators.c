#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d",&n, &k);

    int max_and = 0, max_or = 0, max_xor = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            int _and = a & b;
            int _or = a | b;
            int _xor = a ^ b;
            if (_and < k && _and > max_and) max_and = _and;
            if (_or < k && _or > max_or) max_or = _or;
            if (_xor < k && _xor > max_xor) max_xor = _xor;
        }
    }
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
    return 0;
}