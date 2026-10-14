//Write a program to add n fractions
#include<stdio.h>
struct fract{
    int num,den;
};
typedef struct fract Fract;
Fract input(){
    Fract a;
    printf("Enter the numerator and the denominator: ");
    scanf("%i%i",&a.num,&a.den);
    return a;
}
Fract sum(Fract a,Fract b){
    Fract result;
    result.den=a.den*b.den;
    result.num=a.num*b.den+a.den*b.num;
    return result;
}
Fract calculate(int n,Fract arr[n]){
    Fract result=arr[0];
    for(int i=1;i<n;i++){
        result=sum(result,arr[i]);
    }
    return result;
}
int HCF(int a,int b){
    int r=a%b;
    while(r>0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
Fract reduce(Fract result){
    int great=(result.num>result.den)?result.num:result.den;
    int small=(result.num<result.den)?result.num:result.den;
    int hcf=HCF(great,small);
    result.num/=hcf;
    result.den/=hcf;
    return result;
}
void output(int n,Fract result){
    printf("The sum of the %i fractions is %i/%i.",n,result.num,result.den);
}
int main(){
    int n;
    printf("Enter the number of fractions to be added: ");
    scanf("%i",&n);
    Fract arr[n];
    for(int i=0;i<n;i++){
        arr[i]=input();
    }
    Fract result=calculate(n,arr);
    result=reduce(result);
    output(n,result);
    return 0;
}