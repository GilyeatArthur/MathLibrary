#pragma once

struct Matrix3
{
	Matrix3() {}
	union
	{
		float m[3][3];
		Vector3 c[3];
	};
	Matrix3 transpose()
	{
		Matrix3 r;

		r.c[0] = Vector3(m[0][0], m[1][0], m[2][0]);
		r.c[1] = Vector3(m[0][1], m[1][1], m[2][1]);
		r.c[2] = Vector3(m[0][2], m[1][2], m[2][2]);
	}
};