#include "BootScene.h"
#include "BaseScene.h"
#include "../Object/BoxObject.h"
#include "../Manager/ObjectManager.h"
#include <DxLib.h>

BootScene::BootScene()
    : BaseScene("BootScene") {
    Init();
}

BootScene::~BootScene() {
}

void BootScene::Update() {
    ObjectManager::GetInstance().UpdateObject(GetName());

    counter_++;
}

void BootScene::Draw() {
    ObjectManager::GetInstance().DrawObject(GetName());

    DrawFormatString(0, 0, GetColor(255, 255, 255), "BootScene: %d", counter_);
}

void BootScene::Init() {
    counter_ = 0;

    ObjectManager& objManager = ObjectManager::GetInstance();
    objManager.AddObject(GetName(), new BoxObject(Location2D(100.0f, 100.0f), Vector2D(0.0f, 0.0f)));
}

void BootScene::Release() {
}
