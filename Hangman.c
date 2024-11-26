#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


char *chooseRandomWord(){
    char *words[]= {"fireman", "hangman", "policeman" , "guardman" , "conman"};
    int randomIndex;
    srand((unsigned int )time(NULL));
    randomIndex= rand()% (sizeof(words) / sizeof(words[0]));
     return words [randomIndex];

}

int main(){
    // calling the function 
    char *word= chooseRandomWord();  // Random words 
    int wordLength = strlen(word);  // this count the number of char in words  
    char guessed [wordLength +1]; // allocate space for 0 
    memset(guessed,'_',wordLength);// will provide _ till wordlength
    guessed[wordLength]= '\0';      // terminates at 0.

    int attempts =4;
    printf("Welcome to Hangman !");

    while(attempts >0 && strcmp(word, guessed)!=0){
         printf("Current word :%s\n", guessed);
         printf("Attempt left :%d\n", attempts);

         char guess;
         printf("Enter your guess :");
         scanf(" %c",&guess);

         int found =0;
         for(int i =0 ; i<wordLength;i++){
              if(word[i]==guess &&guessed[i]=='_'){
                   guessed[i]=guess;
                  found =1;
              }
              
         }
         if (! found){
             printf("Incorrect guess .Try again \n");
                attempts --;
             
         }

    }
    if(strcmp(word, guessed)==0){
        printf("Congratulations You guessed the word :%s\n",word);
    }
    else{
        printf("You guessed wrong! ,Better luck next time the correct word was :%s\n", word);
    }
    return 0;
}