#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // To use boolean data type

int main()
{
    // Displaying when criteria match
    printf("Fan profile!! updating......\n");
    int battery = 100;
    bool ispluggedIn = true; // sumilating that the system is plugged in .
    fflush(stdout);
    char lastmode[100] = "";
    while (battery != 0)
    {
        char currentMode[100] = "";
        if (ispluggedIn)
        {
            sprintf(currentMode, "Plugged in : performance mode...6000RPM\n");
        }
        else
        {
            if (battery == 100)
            {
                sprintf(currentMode, "Performance mode.... 6000RPM \n");
                Sleep(3000);
            }

            else if (battery >= 60 && battery < 80)
            {
                sprintf(currentMode, "Balanced Mode.... 4000RPM battery left :%d%%\n", battery);
                Sleep(2000);
            }
            else if (battery < 60 && battery > 20)
            {

                sprintf(currentMode, "whisper mode....2000RPM battery left: %d%%\n", battery);
                Sleep(1000);
            }
            else if (battery <= 20)
            {
                sprintf(currentMode, "Battery low ! Consider plugging in,battery left %d%%\n", battery);
                Sleep(1000);
            }
        }
        if (strcmp(currentMode, lastmode) != 0)
        {
            printf("%s", currentMode);
            strcpy(lastmode, currentMode); // update lastmode to current mode
        }
        //Sleep(1000);
        battery -= 20;
        if (battery == 80)
        {
            ispluggedIn = false;
            printf("Unplugged! On battery\n");
        }
    }
    printf("Battery empty! shutting down.......\n");

    return 0;
}