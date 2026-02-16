#include "../Manager/ObjectManager.h"
#include "../Object/Base2DObject.h"

ObjectManager ObjectManager::GetInstance() {
    static ObjectManager manager;
    return manager;
}

void ObjectManager::AddObject(Base2DObject* obj) {
    objVector.push_back(obj);
}

void ObjectManager::RemoveObject(Base2DObject* obj)
{
}

void ObjectManager::UpdateObjects() {
    for (auto& obj : objVector) {
        obj->Update();
    }
}

void ObjectManager::DrawObjects() {
    for (auto& obj : objVector) {
        obj->Draw();
    }
}
