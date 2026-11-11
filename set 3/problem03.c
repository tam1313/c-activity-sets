#include <stdio.h>
#include <math.h>
void input(int *iterations, double *threshold) {
    printf("Enter the number of loop iterations (e.g., 13): ");
    scanf("%d", iterations);
    printf("Enter the tolerance threshold / epsilon (e.g., 0.0001): ");
    scanf("%lf", threshold);
}
int what_is_wrong(int iterations, double threshold) {
    float x = 0.0f;
    for (int i = 0; i < iterations; i++) {
        x += 17.0f / iterations;
    }
    if (fabs(17.0f - x) < threshold) {
        return 1;
    } else {
        return 0;
    }
}
void output(int result) {
    printf("Result (n) = %d\n", result);
    if (result == 1) {
        printf("Explanation: The floating-point value is within the acceptable error threshold (safe approximation).\n");
    } else {
        printf("Explanation: The floating-point value drifted too far due to precision limitations!\n");
    }
}
int main() {
    int iterations;
    double threshold;
    input(&iterations, &threshold);
    int n = what_is_wrong(iterations, threshold);
    output(n);
    return 0;
}