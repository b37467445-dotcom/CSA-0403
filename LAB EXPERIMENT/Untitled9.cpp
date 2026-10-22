#include <stdio.h>
#include <windows.h>
#include <string.h>

int main() {
    HANDLE hMap;
    char *data;

    hMap = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "MySharedMemory"
    );

    if (hMap == NULL) {
        printf("Shared memory creation failed");
        return 1;
    }

    data = (char *)MapViewOfFile(
        hMap,
        FILE_MAP_ALL_ACCESS,
        0, 0, 1024
    );

    if (data == NULL) {
        printf("Mapping failed");
        CloseHandle(hMap);
        return 1;
    }

    strcpy(data, "Hello from shared memory");

    printf("Message written: %s\n", data);
    printf("Message read: %s\n", data);

    UnmapViewOfFile(data);
    CloseHandle(hMap);

    return 0;
}
