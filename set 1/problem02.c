//2. Write a C program to add two numbers.
#include<stdio.h>
void accept(int *a,int *b){
    printf("Enter two numbers:");
    scanf("%d%d",a,b);
}
int adding(int a,int b){
    int s=a+b;
    return s;
}
void output(int a, int b, int s){
    printf("Sum of the two numbers %d and %d is %d",a,b,s);
}
int main(){
   int a,b,sum;
   accept(&a,&b);
   sum=adding(a,b);
   output(a,b,sum);
   return 0;
}
