//Sum of n different numbers
#include<stdio.h>
int in_num(){
    printf("Enter the number of integers to be added: ");
    int n=0;
    scanf("%i",&n);
    return n;
}
void in_arr(int n,int a[n]){
    for(int i=0;i<n;i++){
        printf("Enter number %i: ",i+1);
        scanf("%i",&a[i]);
    }
}
int sum_of_arr(int n,int a[n]){
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    return sum;
}
void out(int n,int a[n],int sum){
    printf("The sum of the integers is: ");
    for(int i=0;i<n-1;i++)
    printf("%i + ",a[i]);
    printf("%i = %i",a[n-1],sum);
}
int main(){
    int n=in_num();
    int a[n];
    in_arr(n,a);
    int sum=sum_of_arr(n,a);
    out(n,a,sum);
    return 0;
}