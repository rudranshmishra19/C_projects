#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int dice;
    int target =6;
    srand((unsigned int)time(NULL));
    dice = rand() % target +1;

    printf("You rolled :%d\n",dice);
    if(dice==target){
        printf("You won the game \n");

    }
        else{
            printf("You lose the game \n");
        }
    
    
    return 0;
}