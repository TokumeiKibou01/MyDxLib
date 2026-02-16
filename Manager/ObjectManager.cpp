#include "../Manager/ObjectManager.h"
#include "../Object/Base2DObject.h"
#include <string>

ObjectManager& ObjectManager::GetInstance() {
    static ObjectManager manager;
    return manager;
}

void ObjectManager::AddObject(std::string sceneName, Base2DObject* obj) {
    if (objEachSceneMap.find(sceneName) == objEachSceneMap.end()) {
        objEachSceneMap[sceneName] = std::vector<Base2DObject*>();
    }
    std::vector<Base2DObject*>& sceneObjVector = objEachSceneMap.at(sceneName);
    sceneObjVector.push_back(obj);
}

void ObjectManager::RemoveObject(std::string sceneName, Base2DObject* obj) {
}

void ObjectManager::UpdateObject(std::string sceneName) {
    auto& objVector = objEachSceneMap.at(sceneName);
    for (auto& obj : objVector) {
        obj->Update();
    }
}

void ObjectManager::DrawObject(std::string sceneName) {
    auto& objVector = objEachSceneMap.at(sceneName);
    for (auto& obj : objVector) {
        if (obj == nullptr) continue;
        obj->Draw();
    }
}
