#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *chooseRandomWord(){
    char *words [] ={"programming","computer", "laptop", "hangman","speaker ","mouse"};
    int randomIndex;
    srand((unsigned int)time(NULL));
     randomIndex = rand () % (sizeof(words)/sizeof(words[0]));
     return words [randomIndex];
}
int main(){
    char *word= chooseRandomWord();
    int wordlength= strlen(word);
    char guessed [wordlength +1];
    memset(guessed,'_', wordlength);
    guessed [wordlength]= '\0';

     printf("Welcome to Hangman!\n");
     
     int attempts =3; // Overall attempts for users

     while (attempts >0 &&strcmp(word , guessed)!=0){
        printf("Current word :%s\n",guessed);
        printf("Attempt left :%d\n",attempts);

        char guess;
        printf("Enter your guess :");
        scanf(" %c", &guess);

        int found =0;
        for (int i=0;i<wordlength ;i++){
            if(word[i]==guess && guessed [i]=='_' ){
                    guessed[i]=guess;
                    found =1;
            }

        }
        if(! found){
            printf("Incorrect guess ,Try again\n");
             attempts --;

        }
     }
     if(strcmp (word,guessed)==0){
        printf("Congratulation you the correct word :%s", word);

     }
     else{
       printf("Sorry, you ran out of attempts. The correct word was: %s\n", word);
     }
     



    return 0;
}