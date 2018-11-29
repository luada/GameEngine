#ifndef __VERTEX_DATA_H__
#define __VERTEX_DATA_H__

#include "Prerequest.h"
#include "Types.h"

namespace GUI
{

	struct Vertex
	{
		void set(float x, float y, float z, float u, float v, uint32 colour)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->u = u;
			this->v = v;
			this->colour = colour;
		}

		float x, y, z;
		uint32 colour;
		float u, v;
	};

	struct VertexQuad
	{
		enum Enum
		{
			CornerLT = 0,
			CornerRT = 1,
			CornerLB = 2,
			CornerLB2 = 3,
			CornerRT2 = 4,
			CornerRB = 5,
			VertexCount = 6
		};

		void set(float l, float t, float r, float b, float z, float u1, float v1, float u2, float v2, uint32 colour)
		{
			vertex[CornerLT].set(l, t, z, u1, v1, colour);
			vertex[CornerRT].set(r, t, z, u2, v1, colour);
			vertex[CornerLB].set(l, b, z, u1, v2, colour);
			vertex[CornerRB].set(r, b, z, u2, v2, colour);
			vertex[CornerRT2] = vertex[CornerRT];
			vertex[CornerLB2] = vertex[CornerLB];
		}

		void set(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float z, float u1, float v1, float u2, float v2, uint32 colour)
		{
			vertex[CornerLT].set(x1, y1, z, u1, v1, colour);
			vertex[CornerRT].set(x2, y2, z, u2, v1, colour);
			vertex[CornerLB].set(x4, y4, z, u1, v2, colour);
			vertex[CornerRB].set(x3, y3, z, u2, v2, colour);
			vertex[CornerRT2] = vertex[CornerRT];
			vertex[CornerLB2] = vertex[CornerLB];
		}

		Vertex vertex[6];
	};

} // namespace GUI

#endif // __VERTEX_DATA_H__
