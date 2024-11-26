#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Apps 5

int main()
{
    // Declaring the size of ram in a mobile
    char **ram = (char **)malloc(Max_Apps * sizeof(char *));
    if (ram == NULL)
    {
        printf("Error !! ");
        return 1; // Exit if memory allocation failed
    }
    // Allocate memory for each app name
    for (int i = 0; i < Max_Apps; i++)
    {
        ram[i] = (char *)malloc(30 * sizeof(char));
        if (ram[i] == NULL)
        {
            printf("memory allocation failed for %d app !\n", i + 1);
            for (int j = 0; j < i; j++) // free allocated memory
            {
                free(ram[j]);
            }
            free(ram);
            return 1;
        }
    }
    // inputting the name of the app
    int app_count = 0; //   counter for loaded apps
    while (1)
    {

        if (app_count == Max_Apps)
        {
            printf("Could not load the app : low memory!!!\n");
            break;
        }

        printf("Enter the name of app %d(or type 'exit' to stop ):", app_count + 1);
        fgets(ram[app_count], 30, stdin);
        ram[app_count][strcspn(ram[app_count], "\n")] = '\0';
        // check if the user want to exit
        if (strcmp(ram[app_count], "exit") == 0)
        {
            break; // Exit the loop if the user input exit
        }

        app_count++;
    }
    if (app_count == 0)
    {
        printf("You did not load any app in ram !! Optimized");
    }
    else
    {
        printf("You have loaded these app into Ram:\n");

        // Displayed the entered app names
        for (int i = 0; i < app_count; i++)
        {
            printf("App %d: %s\n", i + 1, ram[i]);
        }
    }

    // check if the app limit is reached

    for (int i = 0; i < Max_Apps; i++)
    {
        free(ram[i]); // free each app's allocacted memory
    }
    free(ram); // free the memory for app name pointer

    return 0;
}