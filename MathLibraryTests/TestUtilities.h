#pragma once
#define USE_MATH_DEFINES
#include <math.h>

namespace MathLibrary
{
    constexpr auto epsilon = 1e-4;

    inline float AngleFrom2D(float x, float y)
    {
        return atan2f(y, x);
    }

    template<typename T>
    class Approximate
    {
    public:
        const T& ref;
        using Type = T;
        using SubType = decltype(ref[0]);
        Approximate(const T& other) : ref{ other } {}
        bool operator==(const Approximate& other) const {
            return ref.IsApproximatelyEqual(other.ref);
        }

        const SubType& operator[](int i) const {
            return ref[i];
        }
    };

    template<>
    class Approximate<int>
    {
    public:
        const int& ref;
        using Type = int;
        Approximate(const int& other) : ref{ other } {}
        bool operator==(const Approximate<int>& other) const {
            return ref == other.ref;
        }
    };

    template<>
    class Approximate<float>
    {
    public:
        const float& ref;
        using Type = float;
        Approximate(const float& other) : ref{ other }
        {
        }
        bool operator==(const Approximate<float>& other) const {
            return fabs(ref - other.ref) < epsilon;
        }
    };
}