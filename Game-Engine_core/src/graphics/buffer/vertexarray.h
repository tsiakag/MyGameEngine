#pragma once
#include <vector>
#include <GL/glew.h>
#include "buffer.h"

namespace MyGameEngine { namespace graphics {

	class VertexArray {
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffers; //you can not use this if you dont want memory control

	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* buffer, GLuint index);
		void bind() const;
		void unbind() const;
	};




}}