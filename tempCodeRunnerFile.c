#include <stdio.h>
#include <windows.h>
#include <stdbool.h> // To use boolean data type
#include <string.h>

int main()
{
    // Displaying when criteria match
    printf("Fan profile!! updating......\n");
    int battery = 100;
    bool ispluggedIn = true; // Simulating that the system is plugged in.
    fflush(stdout);
    char lastmode[100] = "";
    int lastBatteryLevel = -1; // Initialize to an invalid level

    while (battery != 0)
    {
        char currentMode[100] = "";

        // Determine current mode based on battery status and whether plugged in
        if (ispluggedIn)
        {
            sprintf(currentMode, "Plugged in: performance mode... 6000RPM\n");
        }
        else
        {
            // Check battery levels and set current mode accordingly
            if (battery >= 60)
            {
                sprintf(currentMode, "Balanced Mode.... 4000RPM, battery left: %d%%\n", battery);
            }
            else if (battery < 60 && battery > 20)
            {
                sprintf(currentMode, "Whisper mode.... 2000RPM, battery left: %d%%\n", battery);
            }
            else if (battery <= 20)
            {
                sprintf(currentMode, "Battery low! Consider plugging in, battery left: %d%%\n", battery);
            }
        }

        // Only print when the current mode or battery level changes
        if (strcmp(currentMode, lastmode) != 0 || battery != lastBatteryLevel)
        {
            printf("%s", currentMode);
            strcpy(lastmode, currentMode); // Update lastmode to current mode
            lastBatteryLevel = battery; // Update last battery level
        }

        Sleep(3000); // Pause before next battery update
        battery -= 20; // Decrease battery level by 20

        if (battery == 80 && ispluggedIn) // Only if still plugged in
        {
            ispluggedIn = false; // Change plugged status
            printf("Unplugged! On battery\n");
        }
    }
    printf("Battery empty! Shutting down.......\n");

    return 0;
}
