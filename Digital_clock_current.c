#include <stdio.h>
#include <time.h>
#include <windows.h>

int main()
{
    while (1)
    {
        // store time in no readable format
        time_t now;
        // Get the current time in sec since the unix epoch
        time(&now);
        // convert time in broken human readable

        struct tm *local = localtime(&now);
        // clear console for window
        system("cls");
        printf("%02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);
        // sleep for 1 seconds
        Sleep(1000);
    }
    return 0;
}