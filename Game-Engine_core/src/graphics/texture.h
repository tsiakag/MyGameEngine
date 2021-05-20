#pragma once

#include <string>
#include <GL/glew.h>
#include <FreeImage.h>
#include "../utilities/imageload.h"

namespace MyGameEngine { namespace graphics {

	class Texture {
	private:
		std::string m_FileName; //for debuggin
		GLuint m_TID;
		GLsizei m_Width, m_Height;

	public:
		Texture(const std::string& filename);
		~Texture();

		void bind() const;
		void unbind() const;

		inline const unsigned int getID() const { return m_TID; }
		inline const unsigned int getWidth() const { return m_Width; }
		inline const unsigned int getHeight() const { return m_Height; }
	private:
		GLuint load();

	};

}}