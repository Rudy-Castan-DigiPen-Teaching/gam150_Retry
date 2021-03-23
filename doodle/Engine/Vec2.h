/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Vec2.h
Author: Yujin Park
Creation date: 03/15/2021
-----------------------------------------------------------------*/
#pragma once
#include <cmath>
#include <limits>

namespace math
{
    [[nodiscard]] constexpr double abs(double d) noexcept { return (d < 0.0) ? -d : d; }

    [[nodiscard]] constexpr bool is_equal(double d1, double d2) noexcept
    {
        return abs(d1 - d2) <= std::numeric_limits<double>::epsilon() * abs(d1 + d2);
    }

    [[nodiscard]] constexpr bool is_equal(int i1, int i2) noexcept { return i1 == i2; }

    struct [[nodiscard]] vec2
    {
        double x, y;

        constexpr vec2() noexcept : vec2(0, 0) {}
        constexpr vec2(double _x, double _y) noexcept : x(_x), y(_y) {};
        constexpr vec2(double value) noexcept : vec2(value, value) {}
        constexpr vec2(const vec2& v) noexcept = default;

        constexpr vec2& operator+=(const vec2& vec) noexcept; // v += v2

        constexpr vec2& operator-=(const vec2& vec) noexcept; // v -= v2

        constexpr vec2& operator*=(double value) noexcept;    // v *= 2.0

        constexpr vec2& operator/=(double value) noexcept;    // v /= 2.0

        constexpr vec2 operator*(double value) noexcept;      // v = v2 * 2.0

        constexpr vec2 operator/(double value) noexcept;      // v = v2 / 2.0


        [[nodiscard]] constexpr double LengthSquared() noexcept;
        constexpr vec2 Normalize() noexcept;
    };

    constexpr vec2 operator+(const vec2& lv, const vec2& rv) noexcept;  // v = v1 + v2

    constexpr vec2 operator-(const vec2& lv, const vec2& rv) noexcept;  // v = v1 - v2

    constexpr vec2 operator-(const vec2& rv) noexcept;                  // v = -v1

    constexpr vec2 operator*(const vec2& lv, double rv) noexcept;       // v = v2 * 2.0

    constexpr vec2 operator*(double lv, const vec2& rv) noexcept;       // v = 2.0 * v2

    constexpr vec2 operator/(const vec2& lv, double rv) noexcept;       // v = v2 / 2.0

    [[nodiscard]] constexpr bool operator==(const vec2& lv, const vec2& rv) noexcept; // v == v2

    [[nodiscard]] constexpr bool operator!=(const vec2& lv, const vec2& rv) noexcept; // v != v2


    struct [[nodiscard]]ivec2
    {
        int x, y;

        constexpr ivec2() noexcept : ivec2(0, 0) {}
        constexpr ivec2(int _x, int _y) noexcept : x(_x), y(_y) {};
        constexpr ivec2(int value) noexcept : ivec2(value, value) {}
        constexpr ivec2(const ivec2& v) noexcept = default;

        constexpr ivec2& operator+=(const ivec2& vec) noexcept; // v += v2

        constexpr ivec2& operator-=(const ivec2& vec) noexcept; // v -= v2

        constexpr ivec2& operator*=(int value) noexcept; // v *= 2.0

        constexpr ivec2& operator/=(int value) noexcept; // v /= 2.0

        constexpr ivec2 operator*(int value) noexcept;      // v = v2 * 2

        constexpr vec2 operator*(double value) noexcept;    // v = v2 * 2.0

        constexpr ivec2 operator/(int value) noexcept;      // v = v2 / 2

        constexpr vec2 operator/(double value) noexcept;    // v = v2 / 2.0


        constexpr operator vec2()
        {
            return vec2{ static_cast<double>(this->x), static_cast<double>(this->y) };
        }
    };

    constexpr ivec2 operator+(const ivec2& lv, const ivec2& rv) noexcept;  // v = v1 + v2

    constexpr ivec2 operator-(const ivec2& lv, const ivec2& rv) noexcept;  // v = v1 - v2

    constexpr ivec2 operator-(const ivec2& rv) noexcept;                   // v = -v1

    constexpr ivec2 operator*(const ivec2& lv, int value) noexcept;

    constexpr ivec2 operator*(int value, const ivec2& rv) noexcept;

    constexpr ivec2 operator/(const ivec2& lv, int value) noexcept;

    constexpr vec2 operator*(double value, const ivec2& rv)noexcept;

    [[nodiscard]] constexpr bool operator==(const ivec2& lv, const ivec2& rv) noexcept;  // v == v2

    [[nodiscard]] constexpr bool operator!=(const ivec2& lv, const ivec2& rv) noexcept;  // v != v2

}

#include "Vec2.inl"
