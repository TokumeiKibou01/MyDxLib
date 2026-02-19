#include "DebugWin32Window.h"
#include <thread>

DebugWin32Window::DebugWin32Window()
{
    isRunning = false;
}

DebugWin32Window::~DebugWin32Window()
{
}

void DebugWin32Window::runThread(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {
    std::thread thread([=]() {
        this->initWindow(hInstance, hPrevInst, lpCmdLine, nCmdShow);
        }
    );

    thread.detach(); // スレッドを手放す（※独立して動く）
}

int DebugWin32Window::initWindow(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc; //ウインドウクラス
    wc.cbSize = sizeof(WNDCLASSEX); //構造体のサイズ
    wc.hInstance = hInstance; //インスタンスハンドル
    wc.lpszClassName = "DebugWindow"; //クラス名
    wc.lpfnWndProc = WndProc; //
    wc.style = CS_VREDRAW | CS_HREDRAW;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
    wc.hCursor = LoadCursor(NULL, IDC_UPARROW);
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    RegisterClassEx(&wc);

    HWND hwnd = nullptr;
    hwnd = CreateWindowA(
        "DebugWindow",
        "デバックウインドウ",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        1280,
        720,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    if (hwnd == nullptr) {
        return -1;
    }
    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            isRunning = false;
        } else {
            isRunning = true;
        }
    }
    return 0;
}

LRESULT DebugWin32Window::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_COMMAND:
        break;
    default:
        break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
