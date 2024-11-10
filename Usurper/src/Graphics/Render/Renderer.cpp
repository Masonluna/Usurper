#include "Renderer.h"



void Usurper::Renderer::Clear()
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Usurper::Renderer::Draw(const VertexBuffer& vb, const IndexBuffer& ib, const Shader& shader)
{
	shader.Bind();
	vb.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

