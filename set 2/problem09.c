//Program to print memory addresses of variables and array elements
#include <stdio.h>
int main()
{
    int a;
    int b;
    int c[10]={1,2,3,4,5,6,7,8,9,10};
    int *pa = c;
    printf("Address of a is %p\nAddress of b is %p\n",&a,&b);
    for(int i=0;i<10;i++,pa++)
    {
        printf("%p %p %p\n",&c[i],pa,c+i,*pa,c[i],*(c+i));
       
    }
    return 0;
}