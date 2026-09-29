//Write a program to read and print the points of a polygon
#include<stdio.h>
struct points{
    float x,y;
};
typedef struct points Point;
struct polygon{
    char name[20];
    int n;
    Point points[20];
};
typedef struct polygon Polygon;
Polygon input(){
    Polygon p;
    printf("Enter the name of the polygon and the number of points(<=20)\n");
    scanf("%s%i",p.name,&p.n);
    for(int i=0;i<p.n;i++){
        printf("Enter point %i: ",i+1);
        scanf("%f%f",&p.points[i].x,&p.points[i].y);
    }
    return p;
}
void output(Polygon p){
    int i;
    printf("The points of the %s are: ",p.name);
    for(i=0;i<p.n-1;i++)
    printf("(%.2f,%.2f), ",p.points[i].x,p.points[i].y);
    printf("(%.2f,%.2f)",p.points[i].x,p.points[i].y);
}
int main(){
    Polygon p;
    p=input();
    output(p);
    return 0;
}