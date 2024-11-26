    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <time.h>

    // Function to choose a random word from an array
    char* chooseRandomWord() { // just like int *ptr ..
    char* words[] = {"programming", "hangman", "computer", "language", "keyboard"};
        int randomIndex;
        
        // Seed the random number generator with the curren t time
        srand((unsigned int)time(NULL));

        randomIndex = rand() % (sizeof(words) / sizeof(words[0])); // This will return between 1 to 5 index
        return  words[randomIndex];
    }

    int main() {
        char* word = chooseRandomWord(); //Let's take  hangman 
        int wordLength = strlen(word);  //  7
        char guessed[wordLength + 1];   // 7+1 =8
        memset(guessed, '_', wordLength); 
        guessed[wordLength] = '\0'; 

        int attempts = 3; // Number of allowed incorrect attempts

        printf("Welcome to Hangman!\n");

        while (attempts > 0 && strcmp(word, guessed) != 0) {
            printf("Current word: %s\n", guessed);
            printf("Attempts left: %d\n", attempts);

            char guess;
            printf("Enter your guess: ");
            scanf(" %c", &guess);   

            int found = 0;
            for (int i = 0; i < wordLength; i++) {
                if (word[i] == guess && guessed[i] == '_') {
                    guessed[i] = guess;
                    found = 1;
                }
            }

            if (!found) {
                printf("Incorrect guess. Try again.\n");
                attempts--;
            }       
        }

        if (strcmp(word, guessed) == 0) {
            printf("Congratulations! You guessed the word: %s\n", word);
        } else {
            printf("Sorry, you ran out of attempts. The correct word was: %s\n", word);
        }a

        return 0;
    }

