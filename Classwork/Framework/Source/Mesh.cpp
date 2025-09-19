#include "Core/CoreHeaders.h"

#include "Mesh.h"

namespace fw
{
	Mesh::Mesh(GLenum primitiveType, const std::vector<float>& verts)
	{
		m_numVerts = (int)verts.size()/2;
		m_primitiveType = primitiveType;

		// Generate a buffer for our vertex attributes.
		glGenBuffers( 1, &m_VBO );

		// Set this VBO to be the currently active one.
		glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

		// Copy our attribute data into the VBO.
		glBufferData( GL_ARRAY_BUFFER, sizeof(float)*verts.size(), verts.data(), GL_STATIC_DRAW);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers( 1, &m_VBO );
	}

	void Mesh::draw()
	{
		// Set this VBO to be the currently active one.
		glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

		// Get the attribute variable’s location from the shader.
		// The shader part is commented out here, we'll discuss that later.
		GLint loc = 0; //glGetAttribLocation( pShader->m_Program, "a_Position" );
		glEnableVertexAttribArray( loc );

		// Describe the attributes in the VBO to OpenGL.
		glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0 );

		// Draw the primitive.
		glDrawArrays( m_primitiveType, 0, m_numVerts );
	}
} // namespace fw
