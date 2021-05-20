#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h> 
#include "../utilities/fileutils.h"
#include "../maths/maths.h"

namespace MyGameEngine { namespace graphics {

	class Shader {
	private:
		const char *m_VertPath, *m_FragPath;

	public:
		GLuint m_ShaderID;
		Shader(const char* vertPath, const char* fragPath);
		~Shader();
		
		void setUniform1f(const GLchar* name, float value);
		void setUniform1fv(const GLchar* name, float* value, int count);
		void setUniform1i(const GLchar* name, int value);
		void setUniform1iv(const GLchar* name, int* value, int count);
		void setUniform2f(const GLchar* name, const maths::vec2 &vector);
		void setUniform3f(const GLchar* name, const maths::vec3 &vector);
		void setUniform4f(const GLchar* name, const maths::vec4 &vector);
		void setUniformMat4(const GLchar* name, const maths::mat4& matrix);

		void enable() const;
		void disable() const;

	private:
		GLint getUniformLocation(const GLchar* name);
		GLuint load();
	};



} }