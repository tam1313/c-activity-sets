//
#include<stdio.h>
int in(){
    printf("Enter the series limit: ");
    int n=0;
    scanf("%d",&n);
    return n;
}
int sum(int n){
    int s=0;
    for(int i=1;i<=n;i++)
    s=s+i;
    return s;
}
void out(int n,int s){
    for(int i=1;i<=n;i++){
        if(i!=n) printf("%d + ",i);
        else printf("%d = ",i);
    }
    printf("%d\n",s);
}
int main(){
    int a=in();
    int result=sum(a);
    out(a,result);
    return 0;
}