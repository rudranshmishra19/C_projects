#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

// function to list all running process
void ListProcesses()
{
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    // Take  a snapshot of all process in the system
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        printf("Failed to create process snapshot .\n");
        return;
    }
    pe32.dwSize = sizeof(PROCESSENTRY32);
    printf("The size of processentry32 is %zu bytes\n",pe32);

    // Retrieve information about the first process
    if (!Process32First(hProcessSnap, &pe32))
    {
        printf("Failed to retrive information about the first process\n");
        CloseHandle(hProcessSnap); // Clean the snapshot object
        return;
    }

    // now walk the snapshot of processess
    printf("%-30s  %-10s\n", "process Name", "PID");
    do
    {
        printf("%-35s  %-10u\n", pe32.szExeFile, pe32.th32ProcessID);
    } while (Process32Next(hProcessSnap, &pe32));
    CloseHandle(hProcessSnap); // clean up the snapshot object
}

int main(void)
{
    ListProcesses();

    return 0;
}       