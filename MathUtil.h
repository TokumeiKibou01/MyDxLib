#pragma once
#include <cmath>

namespace MathUtil {

    const float PI_F = 3.14159265f;
    const double PI_D = 3.14159265358979323846;

    namespace Lerp {
        inline float easeInOutSine(float x) {
            return -(cosf(x * PI_F) / 2);
        }

        template <typename T>
        inline T Lerp(T start, T end, float rate, float (*easeFunc)(float) = nullptr) {
            if (easeFunc != nullptr) {
                rate = easeFunc(rate);
            }
            return (end - start) * rate + start;
        }
    }
}