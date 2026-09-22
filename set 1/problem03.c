//Write a program find the square root of a number using babylonian method.
#include<stdio.h>
#include<math.h>
float in()
{
    float x;
    printf("Enter a number: ");
    scanf("%f",&x);
    return x;
}
float babylon(float n){
    float guess = n / 2, nextguess=(guess + n / guess) / 2;
    while(fabs(nextguess - guess) >= 0.0001){
        guess = nextguess;
        nextguess = (guess + n / guess) / 2;
    }
    return nextguess;
}
void out(float sqr){
    printf("The square root according to babylonian method is: %f\n",sqr);
}
int main(){
    float a = in();
    float sqroot = babylon(a);
    out(sqroot);
    return 0;
}