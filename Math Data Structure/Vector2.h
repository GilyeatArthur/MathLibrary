#pragma once



namespace amw
{
	struct vec2
	{
		union
		{
			struct { float x, y; };
			float v[2];
		};
		static vec2 fromAngle(float angle);
		//unary
		float magnitude() const;
		float angle() const;
		vec2 normal() const;
		vec2 perp() const;
		void normalize();
		vec2 operator-() const;
	};
	//binary
	float dot(const vec2 &lhs, const vec2 &rhs);
	vec2 operator+(const vec2 &lhs, const vec2 &rhs);
}