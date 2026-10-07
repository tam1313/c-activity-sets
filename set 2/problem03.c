//
#include<stdio.h>
struct circle{
    float rad,area;
};
typedef struct circle Circle;
Circle in(){
    Circle c;
    printf("Enter radius of circle: ");
    scanf("%f",&c.rad);
    return c;
}
Circle area(Circle c){
    c.area=3.14*c.rad*c.rad;
    return c;
}
Circle greatest(Circle c1,Circle c2,Circle c3){
    Circle great;
    great=(c1.area>c2.area)?((c1.area>c3.area)?c1:c3):((c2.area>c3.area)?c2:c3);
    return great;
}
void out(Circle great,Circle c1, Circle c2, Circle c3){
    printf("Circle with the largest area from Radius %.2f, Radius %.2f and Radius %.2f is Radius %.2f with area %.2f.\n",c1.rad,c2.rad,c3.rad,great.rad,great.area);
}
int main(){
    Circle c1,c2,c3,great;
    c1=in();
    c2=in();
    c3=in();
    c1=area(c1);
    c2=area(c2);
    c3=area(c3);
    great=greatest(c1,c2,c3);
    out(great,c1,c2,c3);
    return 0;
}