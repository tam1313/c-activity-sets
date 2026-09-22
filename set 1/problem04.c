//Write a program to find the largest of three numbers using 4 functions.
#include<stdio.h>
int in(){
    int a=0;
    scanf("%d",&a);
    return a;
}
int great(int a,int b,int c){
    int g=(a>b)?((a>c)?a:b):((b>c)?b:c);
    return g;
}
void out(int large){
    printf("The largest of the three numbers is %d\n",large);
}
int main(){
    printf("Enter three numbers: ");
    int x=in(),y=in(),z=in();
    int big=great(x,y,z);
    out(big);
    return 0;
}