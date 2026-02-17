#pragma once
#include <vector>
#include <map>
#include <string>
#include "../Object/Base2DObject.h"

class ObjectManager {
private:
    // std::vector<Base2DObject*> objAllSceneVector;
    std::map<std::string, std::vector<Base2DObject*>> objEachSceneMap;
public:
    static ObjectManager& GetInstance();

    void AddObject(std::string sceneName, Base2DObject* obj);
    void RemoveObject(std::string sceneName, Base2DObject* obj);

    template<class C> C* GetDrawObject(std::string sceneName) {
        std::vector<Base2DObject*>& sceneObjVector = objEachSceneMap.at(sceneName);
        for (Base2DObject* obj : sceneObjVector) {
            if (obj == nullptr) continue;
            C* instance = dynamic_cast<C*>(obj);
            if (instance != nullptr) {
                return instance;
            }
        }
        return nullptr;
    }

    template<class C> std::vector<C*> GetDrawObjects(std::string sceneName) {
        std::vector<C*> base;
        std::vector<Base2DObject*>& sceneObjVector = objEachSceneMap.at(sceneName);
        for (Base2DObject* obj : sceneObjVector) {
            if (obj == nullptr) continue;
            C* instance = dynamic_cast<C*>(obj);

            if (instance != nullptr) {
                base.push_back(instance);
            }
        }
        return base;
    }

    void UpdateObject(std::string sceneName);
    void DrawObject(std::string sceneName);
};

