#include <stdio.h>
int input() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    return n;
}
int fibo() {
    static int a = 0;
    static int b = 1;
    int temp = a;
    a = b;
    b = temp + b;
    return temp;
}
void output(int n) {
    printf("The first %d Fibonacci numbers are:\n", n);
    for(int i = 0; i < n; i++) {
        int f = fibo();
        printf("%d ", f);
    }
    printf("\n");
}
int main() {
    int n = input();
    output(n);
    return 0;
}