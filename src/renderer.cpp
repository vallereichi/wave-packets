#include "renderer.h"
#include <iostream>

void Renderer::Clear() const {
    GLCall( glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const VertexBuffer& vb, const Shader& shader) const {
    shader.Bind();
    va.Bind();
    vb.Bind();
    GLCall( glDrawArrays(GL_POINTS, 0, vb.getCount()));
}