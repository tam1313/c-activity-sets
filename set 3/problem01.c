#include <stdio.h>
int input() {
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    return n;
}
int count_bits(unsigned int n) {
    int count = 0;
    int total_bits = sizeof(n) * 8;
    printf("\nb");
    for(int i = total_bits - 1; i >= 0; i--) {
        int bit = (n >> i) & 0x1;
        
        printf("%d", bit);
        
        if (bit == 1) {
            count += 1;
        }
    }
    printf("\n");
    return count;
}
int output(int n, int count) {
    printf("The number of 1 bits in %d is %d\n", n, count);
    return 0;
}
int main() {
    int n;
    n = input();
    int count = count_bits(n);
    output(n, count);
    return 0;
}