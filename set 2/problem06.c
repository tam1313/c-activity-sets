//Write a program to add two fractions and display the result in the most reduced form
#include<stdio.h>
struct fraction{
    int numerator,denominator;
};
typedef struct fraction Fraction;
Fraction input(){
    Fraction a;
    printf("Enter the numerator: ");
    scanf("%i",&a.numerator);
    printf("Enter the denominator: ");
    scanf("%i",&a.denominator);
    return a;
}
Fraction sum(Fraction a,Fraction b){
    Fraction add;
    add.denominator=a.denominator*b.denominator;
    add.numerator=a.numerator*b.denominator+b.numerator*a.denominator;
    return add;
}
int hcf(int a,int b){
    int r=a%b;
    while(r>0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
Fraction calculate(Fraction add){
    int big=(add.numerator>add.denominator)?add.numerator:add.denominator;
    int small=(add.numerator<add.denominator)?add.numerator:add.denominator;
    int HCF=hcf(big,small);
    add.numerator/=HCF;
    add.denominator/=HCF;
    return add;
}
void output(Fraction a,Fraction b,Fraction result){
    printf("The most reduced form of the sum of %i/%i and %i/%i is %i/%i.",a.numerator,a.denominator,b.numerator,b.denominator,result.numerator,result.denominator);
}
int main(){
    Fraction a=input();
    Fraction b=input();
    Fraction add=sum(a,b);
    add=calculate(add);
    output(a,b,add);
    return 0;
}