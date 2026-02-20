#pragma once
#include <string>
#include "BaseObject.h"
#include "../Library/Location2D.h"
#include "../Library/Vector2D.h"

class Base2DObject : public BaseObject {
protected:
    Location2D location_;
    Vector2D vector_;
public:
    Base2DObject();
    Base2DObject(const std::string& name, const Location2D& location, const Vector2D& vector, const bool& isAlive);
    ~Base2DObject();

    Location2D GetLocation() { return location_; };
    void SetLocation(const Location2D& loc) { location_ = loc; };
    Vector2D GetVector() { return vector_;  };
    void SetVector(const Vector2D& vec) { vector_ = vec; };
};

