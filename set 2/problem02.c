//Write a program to find the area of a circle
#include<stdio.h>
struct circle{
    float rad,per,area;
};
typedef struct circle Circle;
Circle input(){
    Circle c;
    printf("Enter the radius of the circle: ");
    scanf("%f",&c.rad);
    return c;
}
Circle compute(Circle c){
    c.area=3.14*c.rad*c.rad;
    c.per=2*3.14*c.rad;
    return c;
}
void output(Circle c){
    printf("The perimeter of the circle of radius %.2f is: %.2f\n",c.rad,c.per);
    printf("The area of the circle of radius %.2f is: %.2f\n",c.rad,c.area);
}
int main(){
    Circle c;
    c=input();
    c=compute(c);
    output(c);
    return 0;
}