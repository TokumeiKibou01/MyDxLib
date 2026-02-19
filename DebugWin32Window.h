#pragma once
#include <Windows.h>

class DebugWin32Window {
private:
    bool isRunning;

    DebugWin32Window();
    ~DebugWin32Window();
public:
    static DebugWin32Window& GetInstance() {
        static DebugWin32Window instance;
        return instance;
    }

    int initWindow(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow);
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};