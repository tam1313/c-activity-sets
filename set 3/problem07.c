#include<stdio.h>
void input(int n,int a[n]){
    printf("Enter the elements in the row: ");
    for(int i=0;i<n;i++){
        scanf("%i",&a[i]);
    }
}
void copy(int n,int a[n],int x[n]){
    for(int i=0;i<n;i++){
        x[i]=a[i];
    }
}
void sort(int n,int x[n]){
    int f;
    for(int i=0;i<n;i++){
        f=0;
        for(int j=0;j<n-i-1;j++){
            if(x[j]>x[j+1]){
                x[j]+=x[j+1];
                x[j+1]=x[j]-x[j+1];
                x[j]-=x[j+1];
                f=1;
            }
        }
        if(f==0){
            break;
        }
    }
}
int verify(int n,int x[n]){
    for(int i=0;i<n;i++){
        if(x[i]!=i+1)
        return 0;
    }
    return 1;
}
void output(int r){
    if (r) printf("Row is fine");
    else printf("Row is not fine");
}
int main(){
    int n=9;
    int a[n];
    int x[n];
    input(n,a);
    copy(n,a,x);
    sort(n,x);
    int r=verify(n,x);
    output(r);
    return 0;
}