#pragma once
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/IndexBuffer.h"

namespace Usurper {

	class Mesh
	{
	public:
		Mesh() = default;
		Mesh(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib);
		Mesh(const VertexBuffer& vb, const VertexArray& va);
		~Mesh();

		const VertexBuffer& GetVB() const { return this->m_VB; };
		const IndexBuffer& GetIB() const { return this->m_IB; };
		const VertexArray& GetVA() const { return this->m_VA; };


		void Init();
	private:
		const VertexBuffer& m_VB;
		const IndexBuffer& m_IB;
		const VertexArray& m_VA;
	};

}