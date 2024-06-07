#include "vertexBuffer.h"
#include "debug.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    :
        m_size(size)
{
    GLCall( glGenBuffers(1, &m_rendererID) );
    GLCall( glBindBuffer(GL_ARRAY_BUFFER, m_rendererID) );
    GLCall( glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW) );
}

VertexBuffer::~VertexBuffer()
{
    GLCall( glDeleteBuffers(1, &m_rendererID) );
}

void VertexBuffer::Bind() const
{
    GLCall( glBindBuffer(GL_ARRAY_BUFFER, m_rendererID) );
}

void VertexBuffer::Unbind() const
{
    GLCall( glBindBuffer(GL_ARRAY_BUFFER, 0) );
}