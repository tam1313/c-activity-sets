//
#include<stdio.h>
struct circle{
    float rad,area;
};
typedef struct circle Circle;
void in(int n, Circle cs[n]){
    for(int i=0;i<n;i++){
        printf("Enter radius of circle %d: ",i+1);
        scanf("%f",&cs[i].rad);
    }
}
float find_area(Circle c){
    c.area=3.14*c.rad*c.rad;
    return c.area;
}
float sum(int n, Circle cs[n]){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=cs[i].area;
    }
    return sum;
}
void display_rad(int n,Circle cs[n],float sum){
    for(int i=0;i<n;i++){
        printf("%d. Radius = %.2f\n",i+1,cs[i].rad);
    }
}
void display_area(int n,Circle cs[n],float sum){
    for(int i=0;i<n;i++){
        printf("%d. Area = %.2f\n",i+1,cs[i].area);
    }
    printf("Total Area = %.2f\n", sum);
}
int main(){
    int n;
    printf("Enter number of circles: ");
    scanf("%d",&n);
    Circle cs[n];
    in(n,cs);
    for(int i=0;i<n;i++){
        cs[i].area=find_area(cs[i]);
    }
    float total_area=sum(n,cs);
    display_rad(n,cs,total_area);
    display_area(n,cs,total_area);
    return 0;
}