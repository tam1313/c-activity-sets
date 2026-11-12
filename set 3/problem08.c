#include<stdio.h>
void input(int m,int n,int a[m][n]){
    printf("Enter the sudoku:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%i",&a[i][j]);
        }
    }
}
int check(int n,int x[n]){
    int b[n];
    for(int i=0;i<n;i++)
    b[i]=0;
    for(int i=0;i<n;i++){
        if(b[x[i]-1]==0){
            b[x[i]-1]=x[i];
        }
        else return 0;
    }
    return 1;
}
int checkRows(int m,int n,int a[m][n]){
    for(int i=0;i<m;i++){
        int x[m];
        for(int j=0;j<n;j++){
            x[j]=a[i][j];
        }
        if(check(n,x)==0) return 0;
    }
    return 1;
}
int checkCols(int m,int n,int a[m][n]){
    for(int i=0;i<n;i++){
        int x[n];
        for(int j=0;j<m;j++){
            x[j]=a[j][i];
        }
        if(check(n,x)==0) return 0;
    }
    return 1;
}
int checkCells(int m,int n,int a[m][n]){
    for(int i=0;i<m;i+=3){
        int x[m*n/9];
        int index=0;
        for(int j=0;j<3;j++){
            for(int k=i;k<i+n/3;k++){
                x[index]=a[i+j][k];
                index++;
            }
        }
        if(check(m*n/9,x)==0) return 0;
    }
    return 1;
}
int checkAll(int m,int n,int a[m][n]){
    if(checkRows(m,n,a)&&checkCols(m,n,a)&&checkCells(m,n,a)) return 1;
    return 0;
}
void output(int r,int c,int cell,int all){
    if(all){
        printf("Corrrect rows and columns.");
    }
    else{
        if(r==0) printf("Incorrect rows.\n");
        if(c==0) printf("Incorrect columns.\n");
        if(cell==0) printf("Incorrect cells.\n");
    }
}
int main(){
    int m=9,n=9;
    int a[m][n];
    input(m,n,a);
    int r=checkRows(m,n,a);
    int c=checkCols(m,n,a);
    int cell=checkCells(m,n,a);
    int all=checkAll(m,n,a);
    output(r,c,cell,all);
    return 0;
}