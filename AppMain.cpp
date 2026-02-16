#include <DxLib.h>
#include "BoxObject.h"
#include <vector>
#include "ObjectManager.h"

int InitApp();

namespace {
    ObjectManager objManager = ObjectManager::GetInstance();
    BoxObject* boxObj = new BoxObject(Location2D(100.0f, 100.0f ), Vector2D(0.0f, 0.0f));
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	if (InitApp() != 0) {
		return -1;
	}
	
	while (true) {
		ClearDrawScreen();

        objManager.UpdateObjects();
        objManager.DrawObjects();

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

    objManager.AddObject(boxObj);

	return 0;
}