#pragma once

class Collider
{
public:
	enum SHAPE {e_circle, e_AABB, e_RAY, e_PLANE} shape;
	union
	{
		Circle	circle;
		AABB	aabb;
		Ray		ray;
		Plane	plane;
	};

	Collider();
	ConvexHull chull;
};

CollisionData EvaluateCollision(const class Transform &aT, const Collider &ac, const Transform &bt, const Collider &bc);