#include <DxLib.h>
#include <vector>
#include "Manager/ObjectManager.h"
#include "Object/BoxObject.h"
#include "Manager/SceneManager.h"
#include "DebugWin32Window.h"
#include <thread>

int InitApp();

namespace {
    SceneManager& sceneManager = SceneManager::GetInstance();
    ObjectManager objManager = ObjectManager::GetInstance();
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	if (InitApp() != 0) {
		return -1;
	}

    DebugWin32Window::GetInstance().runThread(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	
	while (true) {
		ClearDrawScreen();

        sceneManager.UpdateScene();
        sceneManager.DrawScene();

        ScreenFlip();
        WaitTimer(16);
		if (ProcessMessage() == -1) {
			break;
		}
	}
	DxLib_End();
	return 0;
}

int InitApp() {

	// ‚c‚wƒ‰ƒCƒuƒ‰ƒŠ‰Šú‰»ˆ—
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(1280, 720, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(0, 0, 0);

	if (DxLib_Init() == -1) {
		DxLib_End();
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);
    SetAlwaysRunFlag(TRUE);
    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE); 
	return 0;
}