#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

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