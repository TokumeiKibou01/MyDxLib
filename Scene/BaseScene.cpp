#include "BaseScene.h"

BaseScene::BaseScene(std::string name) {
    name_ = name;
}

std::string BaseScene::GetName() {
    return name_;
}
