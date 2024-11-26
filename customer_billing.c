#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
     const char *items[]={"Rice ","sugar", "wheat", "Maggi","soap",NULL};
     

    int num;
    printf("Welcome to Dmart!\n");
    printf("Enter the num of item :");
    scanf("%d",&num);
    for(int i=0;items[i]!=NULL;i++){
        printf("%d.%s ",i+1,items[i]);
    }
    while(num !=0 ){
       switch (num )
       {
       case 1:
            printf("You have selected %s.\n",items[0] );
        break;
        case 2:
            printf("you have selected %s")
       default:
        break;
       }

    }
    



    return 0;
}