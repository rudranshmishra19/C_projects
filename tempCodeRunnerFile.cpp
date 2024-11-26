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
    int lastBatteryBracket = -1; // Initialize to an invalid level

    while (battery != 0)
    {
        char currentMode[100] = "";
        int currentBatteryBracket = 0; // Initialize current battery bracket

        // Determine current mode based on battery status and whether plugged in
        if (ispluggedIn)
        {
            sprintf(currentMode, "Plugged in: performance mode... 6000RPM\n");
            currentBatteryBracket = 100; // Only one bracket for plugged in
        }
        else
        {
            // Check battery levels and set current mode accordingly
            if (battery >= 60)
            {
                sprintf(currentMode, "Balanced Mode.... 4000RPM, battery left: %d%%\n", battery);
                currentBatteryBracket = 1; // Bracket for 60-100%
            }
            else if (battery < 60 && battery > 20)
            {
                sprintf(currentMode, "Whisper mode.... 2000RPM, battery left: %d%%\n", battery);
                currentBatteryBracket = 2; // Bracket for 21-59%
            }
            else if (battery <= 20)
            {
                sprintf(currentMode, "Battery low! Consider plugging in, battery left: %d%%\n", battery);
                currentBatteryBracket = 3; // Bracket for 0-20%
            }
        }

        // Only print when the current mode has changed or the battery bracket has changed
        if (strcmp(currentMode, lastmode) != 0 || currentBatteryBracket != lastBatteryBracket)
        {
            printf("%s", currentMode);
            strcpy(lastmode, currentMode); // Update lastmode to current mode
            lastBatteryBracket = currentBatteryBracket; // Update last battery bracket
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
