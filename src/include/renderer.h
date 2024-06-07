#pragma once

#include <GL/glew.h>

#include "debug.h"
#include "shader.h"
#include "vertexBuffer.h"
#include "vertexArray.h"

class Renderer
{
    public:
        void Clear() const;
        void Draw(const VertexArray& va, const VertexBuffer& vb, const Shader& shader) const;
};