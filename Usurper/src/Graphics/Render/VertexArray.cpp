#include "Core.h"
#include "VertexArray.h"
#include "Renderer.h"

Usurper::VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererID));
}

Usurper::VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void Usurper::VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererID));

}

void Usurper::VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));

}

void Usurper::VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type,
			element.normalized, layout.GetStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}
