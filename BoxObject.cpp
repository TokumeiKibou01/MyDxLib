#include "BoxObject.h"
#include <DxLib.h>

BoxObject::BoxObject(const Location2D& loc, const Vector2D& vec)
    : Base2DObject("Box", loc, vec, true) {
    color_ = GetColor(255, 255, 255);
    width_ = 100;
    height_ = 100;
}

BoxObject::~BoxObject() {
}

void BoxObject::Update() {
    isAlive_ = true;
}

void BoxObject::Draw() {
    if (!isAlive_) return;

    DrawBox(
        location_.x_ - (width_ / 2), location_.y_ - (height_ / 2),
        location_.x_ + (width_ / 2), location_.y_ + (height_ / 2),
        color_, true
    );
}
