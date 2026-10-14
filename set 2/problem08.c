//Write a program to print the bill of a sweet shop.
#include<stdio.h>
struct item{
    char name[50];
    float price;
    float weight;
    float total_p;
};
typedef struct item Item;
Item input(){
    printf("Enter the name, price and weight of the item: ");
    Item i;
    scanf("%s%f%f",&i.name,&i.price,&i.weight);
    return i;
}
void allInput(int n,Item arr[n]){
    for(int i=0;i<n;i++){
        arr[i]=input();
    }
}
Item totalPrice(Item i){
    i.total_p=i.price*i.weight;
    return i;
}
float amount(int n,Item arr[n]){
    float sum=0.0;
    for(int i=0;i<n;i++){
        arr[i]=totalPrice(arr[i]);
        sum+=arr[i].total_p;
    }
    return sum;
}
void printItem(Item i){
    printf("%s\t%.2f\t%.2f\t%.2f\n",i.name,i.price,i.weight,i.total_p);
}
void output(int n,Item arr[n],float sum){
    printf("Name\t\tPrice\tWeight\tTotal\n");
    for(int i=0;i<n;i++){
        printItem(arr[i]);
    }
    printf("Total Price = %.2f",sum);
}
int main(){
    printf("Enter the total number of items: ");
    int n;
    scanf("%i",&n);
    Item arr[n];
    allInput(n,arr);
    float sum=amount(n,arr);
    output(n,arr,sum);
    return 0;
}