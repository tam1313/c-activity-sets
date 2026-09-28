//Distance between two points using structure
#include<stdio.h>
#include<math.h>
struct point{
    float x,y;
};
typedef struct point Point;
Point input(){
    Point q;
    printf("Enter x and y coordinates: ");
    scanf("%f%f",&q.x,&q.y);
    return q;
}
float distance(Point a,Point b){
    float d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return d;
}
void output(Point a,Point b,float d){
    printf("The distance between (%f,%f) and (%f,%f) is %f.",a.x,a.y,b.x,b.y,d);
}
int main(){
    Point a,b;
    a=input();
    b=input();
    float d=distance(a,b);
    output(a,b,d);
    return 0;
}