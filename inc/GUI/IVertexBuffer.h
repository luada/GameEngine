#ifndef __I_VERTEX_BUFFER_H__
#define __I_VERTEX_BUFFER_H__

#include "Prerequest.h"
#include "VertexData.h"

namespace GUI
{

	class GUI_EXPORT IVertexBuffer
	{
	public:
		virtual ~IVertexBuffer() { }

		virtual void SetVertextCount(size_t value) = 0;
		virtual size_t GetVertextCount() = 0;

		virtual Vertex* Lock() = 0;
		virtual void Unlock() = 0;

	};

} // namespace GUI

#endif // __I_VERTEX_BUFFER_H__
