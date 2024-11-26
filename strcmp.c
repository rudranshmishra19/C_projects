#include<stdio.h>
#include<string.h>

int main(){
    char str1[]="Rudransh";
    char str2[]= "shivangini";

    int result =strcmp(str1,str2);
    if(result==0)
       {
        printf(" str1 and str2 are equal \n");

       }
       else if(result<0){
        printf("The str1 is less than str2\n ");
       }
       else{
        printf("The str1 is greater than str2\n");
       }
    return 0;
}