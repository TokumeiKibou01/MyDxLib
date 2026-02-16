#pragma once
#include "Base2DObject.h"
class BoxObject : public Base2DObject {
private:
    int width_, height_;
    unsigned int color_;
public:
    BoxObject(const Location2D& loc, const Vector2D& vec);
    ~BoxObject();

    void Update() override;
    void Draw() override;
};

