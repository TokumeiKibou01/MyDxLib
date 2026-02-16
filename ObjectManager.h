#pragma once
#include <vector>
#include "Base2DObject.h"

class ObjectManager {
private:
    std::vector<Base2DObject*> objVector;
public:
    static ObjectManager GetInstance();

    void AddObject(Base2DObject* obj);
    void RemoveObject(Base2DObject* obj);
    void UpdateObjects();
    void DrawObjects();
};

