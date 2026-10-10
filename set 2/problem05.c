//Write a program to add three fractions
#include<stdio.h>
struct fraction{
  int numerator,denominator;  
};
typedef struct fraction Fraction;
Fraction in(){
    Fraction a;
    printf("Enter the numerator and denominator of the fraction: ");
    scanf("%i%i",&a.numerator,&a.denominator);
    return a;
}
float adding(Fraction x,Fraction y,Fraction z){
    int d=x.denominator*y.denominator*z.denominator;
    int n=x.numerator*y.denominator*z.denominator+y.numerator*x.denominator*z.denominator+z.numerator*x.denominator*y.denominator;
    float sum=(float)n/d;
    return sum;
}
void out(Fraction x,Fraction y,Fraction z,float sum){
    printf("The sum of %i/%i, %i/%i and %i/%i is %.2f",x.numerator,x.denominator,y.numerator,y.denominator,z.numerator,z.denominator,sum);
}
int main(){
    Fraction x=in(),y=in(),z=in();
    float sum=adding(x,y,z);
    out(x,y,z,sum);
    return 0;
}