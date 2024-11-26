#include<stdio.h>
#include<string.h>

int main(){
    char str[]= "Hello , Rudransh";
     size_t wordLength;
    wordLength = strlen(str);
    printf("Length of the string :%zu\n", wordLength);
    return 0;
}