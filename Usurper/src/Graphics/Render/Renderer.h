#pragma once

#include "VertexBuffer.h"
#include "Shader.h"
#include "IndexBuffer.h"

#include <glad/glad.h>

namespace Usurper {


	class Renderer
	{
	public:
		void Clear();
		void Draw(const VertexBuffer &vb, const IndexBuffer &ib, Shader &shader);

	private:
	};


}