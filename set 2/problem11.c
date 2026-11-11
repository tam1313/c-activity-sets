#include <stdio.h>
#include <stdlib.h>
struct object {
    int type;
    void *shape;
};
typedef struct object Object;
struct circle {
    int type;
    float radius, area;
};
typedef struct circle Circle;
struct rectangle {
    int type;
    float length, breadth, area;
};
typedef struct rectangle Rectangle;
struct triangle {
    int type;
    float base, altitude, area;
};
typedef struct triangle Triangle;
Object input_shape() {
    int n;
    Object O;
    printf("Enter the shape of the object 0 - Circle, 1 - Rectangle, 2 - Triangle: ");
    scanf("%d", &n);
    if (n == 0) {
        Circle *c = malloc(sizeof(Circle));
        c->type = 0;
        printf("Enter the radius of the circle: ");
        scanf("%f", &c->radius);
        c->area = 3.14159 * c->radius * c->radius; // Example area calculation
        O.type = c->type;
        O.shape = c;
    } 
    else if (n == 1) {
        Rectangle *r = malloc(sizeof(Rectangle));
        r->type = 1;
        printf("Enter the length and breadth of the rectangle: ");
        scanf("%f%f", &r->length, &r->breadth);
        r->area = r->length * r->breadth; // Example area calculation
        O.type = r->type;
        O.shape = r;
    } 
    else if (n == 2) {
        Triangle *t = malloc(sizeof(Triangle));
        t->type = 2;
        printf("Enter the base and altitude of the triangle: ");
        scanf("%f%f", &t->base, &t->altitude);
        t->area = 0.5 * t->base * t->altitude; // Example area calculation
        O.type = t->type;
        O.shape = t;
    }
    return O;
}
void output_shape(Object O) {
    if (O.type == 0) {
        Circle *c = (Circle *)O.shape;
        printf("Circle with radius %.2f and area %.2f\n", c->radius, c->area);
    } 
    else if (O.type == 1) {
        Rectangle *r = (Rectangle *)O.shape;
        printf("Rectangle with length %.2f and breadth %.2f and area %.2f\n", r->length, r->breadth, r->area);
    } 
    else if (O.type == 2) {
        Triangle *t = (Triangle *)O.shape;
        printf("Triangle with base %.2f and altitude %.2f and area %.2f\n", t->base, t->altitude, t->area);
    }
}
int main() {
    Object O;
    O = input_shape();
    output_shape(O);
    free(O.shape);
    return 0;
}