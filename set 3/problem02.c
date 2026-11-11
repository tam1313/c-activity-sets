#include <stdio.h>
int input(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    return n;
}
int count_bits(int n){
    int count = 0;
    while(n) {
        count += 1;
        n &= n-1;
    }
    return count;
}
void output(int n, int count){
    printf("The number of bits in %d is %d\n",n,count);
}
int main(){
    int n;
    n= input();
    printf("n = %d\n",n);
    int count;
    count = count_bits(n);
    output(n,count);
}