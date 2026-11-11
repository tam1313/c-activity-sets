#include <stdio.h>
#include <stdlib.h>
struct triangle { 
    float base, altitude, area; 
};
typedef struct triangle Triangle;
void *input() { 
    Triangle *t = malloc(sizeof(Triangle)); 
    printf("Enter base and altitude of a triangle: "); 
    scanf("%f%f", &t->base, &t->altitude); 
    return t; 
}
void output(Triangle t) { 
    printf("The base and altitude of the triangle are %.2f and %.2f\n", t.base, t.altitude); 
}
int main() { 
    void *t; 
    t = input();
    Triangle *tptr = (Triangle *)t;
    output(*(Triangle *)t); 
    free(t);
    return 0;
}