#include <stdio.h>
int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return sum(n - 1) + n;
}
int f(int n) {
    int m;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    m = f(n - 1) + f(n - 2);
    return m;
}
int main() {
    int num;
    printf("Enter a number to find its Fibonacci value: ");
    if (scanf("%d", &num) == 1 && num >= 0) {
        int fib_result = f(num);
        printf("Result: f(%d) = %d\n\n", num, fib_result);
    } else {
        printf("Invalid input for Fibonacci.\n\n");
    }
    printf("Enter a number to calculate the recursive sum down to 0: ");
    if (scanf("%d", &num) == 1 && num >= 0) {
        int sum_result = sum(num);
        printf("Result: sum(%d) = %d\n", num, sum_result);
    }
    else {
        printf("Invalid input for summation.\n");
    }
    return 0;
}