#include <stdio.h>
#include <windows.h>

int main() {
    MSG msg;
    DWORD threadId = GetCurrentThreadId();

    if (!PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE)) {
        printf("Message queue initialized\n");
    }

    PostThreadMessage(threadId, WM_USER, 100, 200);

    if (GetMessage(&msg, NULL, WM_USER, WM_USER) > 0) {
        printf("Message received successfully\n");
        printf("Value 1: %lu\n", (unsigned long)msg.wParam);
        printf("Value 2: %ld\n", (long)msg.lParam);
    }

    return 0;
}
