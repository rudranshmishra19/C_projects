#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    int hours,min,sec;
    hours=min=sec=0;
    while(1){
        // clear output screen
        system("cls");
        // print time HH:MM:SS format
        printf("%02d:%02d:%02d \n",hours,min,sec);
        // clear output in buffer

        fflush(stdout);
        sec++;
        if(sec==60){
            min ++;
            sec=0;
        }
        if(min==60){
            hours++;
            min=0;
        }
        if(hours==24){
            hours=0;
            min=0;
            sec=0;
        }
        Sleep(1000);
    }

    return 0;
}