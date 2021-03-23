/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Vec2.inl
Author: Yujin Park
Creation date: 03/15/2021
-----------------------------------------------------------------*/

namespace math
{
	//vec2

	constexpr math::vec2& math::vec2::operator+=(const vec2& vec)noexcept
	{
		this->x += vec.x;
		this->y += vec.y;

		return *this;
	}

	constexpr math::vec2& math::vec2::operator-=(const vec2& vec)noexcept
	{
		this->x -= vec.x;
		this->y -= vec.y;

		return *this;
	}

	constexpr math::vec2& math::vec2::operator*=(double value)noexcept
	{
		x *= value;
		y *= value;

		return *this;
	}
	constexpr math::vec2& math::vec2::operator/=(double value)noexcept
	{
		x /= value;
		y /= value;

		return *this;
	}

	constexpr math::vec2 math::vec2::operator*(double value) noexcept
	{
		return vec2{ x * value, y * value };
	}

	constexpr math::vec2 math::vec2::operator/(double value) noexcept
	{
		return vec2{ x / value, y / value };
	}

    constexpr math::vec2 operator+(const vec2& lv, const vec2& rv) noexcept
	{
		return vec2{ lv.x + rv.x, lv.y + rv.y };
	}

	constexpr math::vec2 operator-(const vec2& lv, const vec2& rv) noexcept
	{
		return vec2{ lv.x - rv.x, lv.y - rv.y };
	}

	constexpr math::vec2 operator-(const vec2& rv) noexcept
	{
		return vec2{-rv.x, -rv.y};
	}

	constexpr math::vec2 operator*(const vec2& lv, double rv) noexcept
	{
		return vec2{lv.x * rv, lv.y * rv};
	}

	constexpr math::vec2 operator*(double lv, const vec2& rv) noexcept
	{
		return vec2{ lv * rv.x , lv * rv.y };
	}

	constexpr math::vec2 operator/(const vec2& lv, double rv) noexcept
	{
		return vec2{ lv.x / rv , lv.y / rv };
	}

	// Comparisons

	[[nodiscard]] constexpr bool operator==(const vec2& lv, const vec2& rv) noexcept
	{
		double v = 0;
		if (lv.x - rv.x <= std::numeric_limits<double>::epsilon() && lv.y - rv.y <= std::numeric_limits<double>::epsilon())
			v = 1;
		return v;
	}

	[[nodiscard]] constexpr bool operator!=(const vec2& lv, const vec2& rv) noexcept
	{
		double v = 0;
		if (lv.x > rv.x && lv.y > rv.y || lv.x < rv.x && lv.y < rv.y ||
			lv.x < rv.x && lv.y > rv.y || lv.x > rv.x && lv.y > rv.y)
			v = 1;
		return v;
	}

	[[nodiscard]] constexpr double vec2::LengthSquared() noexcept
	{
		return x * x + y * y;
	}

	constexpr math::vec2 vec2::Normalize() noexcept
	{
		return vec2{ x / sqrt(LengthSquared()), y / sqrt(LengthSquared()) };
	}


	//ivec2 ---------------------------------------------------------------------------------------------------------------------

	constexpr math::ivec2& math::ivec2::operator+=(const ivec2& vec)noexcept 
	{
		this->x += vec.x;
		this->y += vec.y;

		return *this;
	}

	constexpr math::ivec2& math::ivec2::operator-=(const ivec2& vec)noexcept
	{
		this->x -= vec.x;
		this->y -= vec.y;

		return *this;
	}

	constexpr math::ivec2& math::ivec2::operator*=(int value)noexcept
	{
		x *= value;
		y *= value;

		return *this;
	}
	constexpr math::ivec2& math::ivec2::operator/=(int value)noexcept
	{
		this->x /= value;
		this->y /= value;

		return *this;
	}



	constexpr math::ivec2 math::ivec2::operator*(int value) noexcept
	{
		return ivec2{x * value, y * value};
	}

	constexpr math::vec2 math::ivec2::operator*(double value)noexcept
	{
		return vec2{ x * value, y * value };
	}

	constexpr math::ivec2 math::ivec2::operator/(int value) noexcept
	{
		return ivec2{ x / value, y / value };
	}

	constexpr math::vec2 math::ivec2::operator/(double value)noexcept
	{
		return vec2{ x / value, y / value};
	}


	constexpr math::ivec2 operator+(const ivec2& lv, const ivec2& rv) noexcept
	{
		return ivec2{ lv.x + rv.x, lv.y + rv.y };
	}

	constexpr math::ivec2 operator-(const ivec2& lv, const ivec2& rv) noexcept
	{
		return ivec2{ lv.x - rv.x, lv.y - rv.y };
	}

	constexpr math::ivec2 operator-(const ivec2& rv) noexcept
	{
		return ivec2{ -rv.x, -rv.y };
	}


	constexpr math::ivec2 operator*(const ivec2& rv, int value) noexcept
	{
		return ivec2{rv.x * value, rv.y * value };
	}

	constexpr math::ivec2 operator*(int value, const ivec2& lv) noexcept
	{
		return ivec2{ value * lv.x , value * lv.y };
	}

	constexpr math::ivec2 operator/(const ivec2& rv, int value) noexcept
	{
		return ivec2{ rv.x / value , rv.y / value };
	}


	constexpr math::vec2 operator*(double value, const ivec2& rv)noexcept
	{
		return vec2{ value * rv.x , value * rv.y };
	}


	[[nodiscard]] constexpr bool operator==(const ivec2& lv, const ivec2& rv) noexcept
	{
		int v = 0;
		if (lv.x - rv.x == 0 && lv.y - rv.y == 0)
			v = 1;

		return v;
	}

	[[nodiscard]] constexpr bool operator!=(const ivec2& lv, const ivec2& rv) noexcept
	{
		int v = 0;
		if (lv.x > rv.x && lv.y > rv.y || lv.x < rv.x && lv.y < rv.y || 
			lv.x < rv.x && lv.y > rv.y || lv.x > rv.x && lv.y > rv.y)
			v = 1;

		return v;
	}

}
