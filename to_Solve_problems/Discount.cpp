#include <cstdio>

int main() {
    double A, B;
    scanf("%lf %lf", &A, &B);

    double ans = (A - B) * 100.0 / A;
    printf("%.15f\n", ans);

    return 0;
}
