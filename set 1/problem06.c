//Write a program to find the lenght of a string.
#include<stdio.h>
#include<string.h>
void accept_string(char s[]){
    printf("Enter a string: ");
    scanf("%s",s);
}
int length(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++){}
    return i;
}
void output(char s[],int len){
    printf("The length of the string \"%s\" is %i.",s,len);
}
int main(){
    char s[50];
    accept_string(s);
    int l=length(s);
    output(s,l);
    return 0;
}