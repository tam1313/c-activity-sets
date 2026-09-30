//Write a programe to find distance between two point using pass by reference.
#include<stdio.h>
#include<math.h>
struct point{
    float x,y;
};
typedef struct point Point;
Point input()
{
    Point p;
    printf("Enter the x and y coordinates of the point: ");
    scanf("%f%f",&p.x,&p.y);
    return p;
}
float distance(Point *p1,Point *p2){
    float d=sqrt(pow(p1->x-p2->x,2)+pow(p1->y-p2->y,2));
    return d;
}
void output(Point *p1,Point *p2,float dist){
    printf("The distance between (%.2f,%.2f) and (%.2f,%.2f) is %.2f.",p1->x,p1->y,p2->x,p2->y,dist);
}
int main(){
    Point p1,p2;
    p1=input();
    p2=input();
    float dist=distance(&p1,&p2);
    output(&p1,&p2,dist);
    return 0;
}