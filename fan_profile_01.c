#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>

int main()
{
    printf("Fan profile updating.....");
    // intializing the battery level to 100
    int battery = 100;
    // simulating the laptop is plugged in
    bool IspluggedIn = true;
    // intialzing the last mode to avoid duplicate printing of same profile
    char lastmode[100] = "";
    // for clearing any buffer before printing 
    fflush(stdout);
    while (battery != 0)
    {
        char currentmode[100] = "";
        if (IspluggedIn)
        {
            sprintf(currentmode, "Plugged in :performance mode....6000RPM\n");
        }
        else
        {
            if (battery == 100)
            {
                sprintf(currentmode, "performance mode....6000RPM\n");
            }
            else if (battery >= 60 && battery < 80)
            {
                sprintf(currentmode, "Balanced mode....4000RPM ,battery left %d%%\n", battery);
            }
            else if (battery < 60 && battery > 20)
            {
                sprintf(currentmode, "whispermode....2000RPM ,battery left %d%%\n", battery);
            }
            else if (battery <= 20)
            {
                sprintf(currentmode, "consider Plugging in battery left %d%%\n", battery);
            }
        }
        if (strcmp(lastmode, currentmode) != 0)
        {
            printf("%s", currentmode);
            strcpy(lastmode, currentmode);
        }
        battery -= 20;
         Sleep(2000);
        if (battery == 80)
        {
            IspluggedIn = false;
            printf("Unplugged! On battery\n");
        }
    }
    printf("Battery empty! shutting down......");

    return 0;
}