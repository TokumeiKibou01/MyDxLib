#include "BootScene.h"
#include "BaseScene.h"
#include <DxLib.h>

BootScene::BootScene()
    : BaseScene("BootScene") {
    counter_ = 0;
}

BootScene::~BootScene() {
}

void BootScene::Update() {
    counter_++;
}

void BootScene::Draw() {
    DrawFormatString(0, 0, GetColor(255, 255, 255), "BootScene: %d", counter_);
}

void BootScene::Init() {
    counter_ = 0;
}

void BootScene::Release() {
}
