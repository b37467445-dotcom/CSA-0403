#include <stdio.h>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent Process ID: %lu\n", GetCurrentProcessId());

    if (CreateProcess(
        "C:\\Windows\\System32\\cmd.exe",
        NULL, NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {

        printf("Child Process ID: %lu\n", pi.dwProcessId);
        printf("Child Parent Process ID: %lu\n",
               GetCurrentProcessId());

        WaitForSingleObject(pi.hProcess, INFINITE);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        printf("Process creation failed!\n");
        return 1;
    }

    return 0;
}
