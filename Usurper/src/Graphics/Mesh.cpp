#include "Mesh.h"

Usurper::Mesh::Mesh(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib)
	: m_VA(va), m_VB(vb), m_IB(ib)
{

}

Usurper::Mesh::Mesh(const VertexBuffer& vb, const VertexArray& va) 
	: m_VA(va), m_VB(vb), m_IB(IndexBuffer())
{}

Usurper::Mesh::~Mesh()
{}

void Usurper::Mesh::Init()
{}
