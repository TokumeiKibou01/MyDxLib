#pragma once
#include <string>
#include "../Library/Location2D.h"
#include "../Library/Vector2D.h"

class Base2DObject {
protected:
    std::string name_;
    Location2D location_;
    Vector2D vector_;
    bool isAlive_;
public:
    Base2DObject();
    Base2DObject(const std::string& name, const Location2D& location, const Vector2D& vector, const bool& isAlive);
    ~Base2DObject();

    virtual void Update() = 0;
    virtual void Draw() = 0;

    Location2D GetLocation() { return location_; };
    void SetLocation(const Location2D& loc) { location_ = loc; };
    Vector2D GetVector() { return vector_;  };
    void SetVector(const Vector2D& vec) { vector_ = vec; };

    bool IsAlive() const { return isAlive_; };
};

