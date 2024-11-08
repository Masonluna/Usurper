#pragma once
#include "Graphics/Shader.h"
#include "Graphics/Mesh.h"

namespace Usurper {

	class Renderable
	{
	public:
		virtual ~Renderable() = default;

		virtual void Draw() const = 0;
		virtual const Shader& GetShader() const = 0;
		virtual const Mesh& GetMesh() const = 0;
	};
}
