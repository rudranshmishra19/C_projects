#include<stdio.h>
#include<string.h>

int main(){
     char str[50]="Learning through coding ";
     printf("Before memset :%s\n", str);
     // we need to add _ in the place of through .. just like fill in the blanks 
     memset(str + 8, '_', 8*sizeof(char) );
     printf("After memset : %s\n",str);
    return 0;
}