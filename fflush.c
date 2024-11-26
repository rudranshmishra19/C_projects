#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    printf("Loading....");
    // flush the output to display "Loading ...." immediately
    fflush(stdout);

    Sleep(2000);
    printf("Done!");

    return 0;
}