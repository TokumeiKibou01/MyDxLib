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
    void UpdateObject(std::string sceneName);
    void DrawObject(std::string sceneName);
};

