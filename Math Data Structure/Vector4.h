#pragma once
 
#include <cmath>
#include <cfloat>

//This was all done with extreme help from Justin Hamm.

#define E_VEC4 Vector4{FLT_EPSILON, FLT_EPSILON, FLT_EPSILON, FLT_EPSILON}

namespace MatLib
{


	__declspec(align(32)) struct Vector4/*Puts all of the variables right next to each other in the code to maximize data efficency*/
	{
		union
		{
			float v[4];
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
		};
#pragma region BinaryOperators

		Vector4& operator+= (const Vector4 &rhs)
		{
			return *this = Vector4{ x + rhs.x, y + rhs.y,z + rhs.z,w + rhs.w };
		}

		Vector4& operator-= (const Vector4 &rhs)
		{
			return *this = Vector4{ x - rhs.x, y - rhs.y,z - rhs.z,w - rhs.w };
		}

		Vector4& operator*= (const float &rhs)
		{
			return *this = Vector4{ x * rhs, y * rhs, z * rhs, w * rhs };
		}

		Vector4& operator/= (const float &rhs)
		{
			return *this = Vector4{ x / rhs, y / rhs, z / rhs, w / rhs };
		}

		Vector4 operator+ (const Vector4 &rhs) const
		{
			Vector4 result = *this;
			result += rhs;
			return result;
		}

		Vector4 operator- (const Vector4 &rhs) const
		{
			Vector4 result = *this;
			result -= rhs;
			return result;
		}

		Vector4 operator* (const float &rhs) const
		{
			Vector4 result = *this;
			result *= rhs;
			return result;
		}

		Vector4 operator/ (const float &rhs) const
		{
			Vector4 result = *this;
			result /= rhs;
			return result;
		}


		bool operator== (const Vector4 &rhs) const
		{
			return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w) || (rhs < *this + E_VEC4 && *this - E_VEC4 < rhs);
		}

		bool operator!= (const Vector4 &rhs) const
		{
			return !(*this == rhs);
		}

		bool operator< (const Vector4 &rhs) const
		{
			return (x < rhs.x - FLT_EPSILON && y < rhs.y - FLT_EPSILON && z < rhs.z - FLT_EPSILON && w < rhs.w - FLT_EPSILON);
		}

		bool operator> (const Vector4 &rhs) const
		{
			return (x > rhs.x + FLT_EPSILON && y > rhs.y + FLT_EPSILON && z > rhs.z + FLT_EPSILON && w > rhs.w + FLT_EPSILON);
		}

		bool operator<= (const Vector4 &rhs) const
		{
			return *this == rhs || *this < rhs;
		}

		bool operator>= (const Vector4 &rhs) const
		{
			return *this == rhs || *this > rhs;
		}
#pragma endregion


#pragma region UnaryOperators

		Vector4& operator-() const
		{
			return Vector4{ -x,-y,-z,-w };
		}
#pragma endregion


#pragma region FunctionHeaders

		float		dot		(const Vector4 &a, const Vector4 &b);

		float		mag		(const Vector4 &v);

		Vector4&	normal	(const Vector4 &v);
		
		Vector4&	lerp	(const Vector4 &a, const Vector4 &b, const float &alpha);

		Vector4		min		(const Vector4 *pts, size_t n);

		Vector4		max		(const Vector4 *pts, size_t n);

#pragma endregion

		void normalize()
		{
			*this = normal(*this);
		}

	};

#pragma region Vector4Methods

	float dot(const Vector4 &a, const Vector4 &b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	float mag(const Vector4 &v)
	{
		return sqrtf(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
	}

	Vector4& normal(const Vector4 &v)
	{
		float m = mag(v);
		return Vector4{ v.x / m,v.y / m,v.z / m,v.w / m };
	}

	Vector4& lerp(const Vector4 &a, const Vector4 &b, const float &alpha)
	{
		return Vector4{ a.x + ((a.x - b.x)*alpha),a.y + ((a.y - b.y)*alpha),a.z + ((a.z - b.z)*alpha) ,a.w + ((a.w - b.w)*alpha) };
	}

	Vector4 min(const Vector4 *pts, size_t n)
	{
		Vector4 temp = pts[0];

		for (size_t i = 1; i < n; ++i)
		{
			if (pts[i].x < temp.x) temp.x = pts[i].x;
			if (pts[i].y < temp.y) temp.y = pts[i].y;
			if (pts[i].z < temp.z) temp.z = pts[i].z;
			if (pts[i].w < temp.w) temp.w = pts[i].w;
		}

		return temp;
	}

	Vector4 max(const Vector4 *pts, size_t n)
	{
		Vector4 temp = pts[0];

		for (size_t i = 1; i < n; ++i)
		{
			if (pts[i].x > temp.x) temp.x = pts[i].x;
			if (pts[i].y > temp.y) temp.y = pts[i].y;
			if (pts[i].z > temp.z) temp.z = pts[i].z;
			if (pts[i].w > temp.w) temp.w = pts[i].w;
		}

		return temp;
	}
#pragma endregion



}