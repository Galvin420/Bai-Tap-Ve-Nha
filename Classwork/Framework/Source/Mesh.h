#pragma once

#include "Core/CoreHeaders.h"

namespace fw
{
    class ShaderProgram;

    class Mesh
    {
    public:
        Mesh(GLenum primitiveType, const std::vector<float>& verts);
        virtual ~Mesh();

        void draw();

    protected:
        GLuint m_VBO = 0;
        int m_numVerts = 0;
        GLenum m_primitiveType = GL_POINTS;
    };
} // namespace fw
