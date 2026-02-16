#include "Base2DObject.h"

Base2DObject::Base2DObject(const std::string& name, const Location2D& location, const Vector2D& vector, const bool& alive) {
    name_ = name;
    location_ = location;
    vector_ = vector;
}

Base2DObject::~Base2DObject() {
}