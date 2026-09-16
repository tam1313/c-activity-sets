//2. Write a C program to add two numbers.
#include<stdio.h>
int main(){
    int x,y,sum;
    printf("Enter two numbers:");
    scanf("%d%d",&x,&y);
    sum=x+y;
    printf("Sum of %d and %d is %d",x,y,sum);
    return 0;
}