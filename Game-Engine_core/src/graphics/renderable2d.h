#pragma once

#include "buffer/buffer.h"
#include "buffer/indexbuffer.h"
#include "buffer/vertexarray.h"

#include "renderer2d.h"
#include "texture.h"

#include "../maths/maths.h"
#include "shader.h"

namespace MyGameEngine { namespace graphics {

	struct VertexData {
		//all data per vertex
		maths::vec3 vertex;
		maths::vec2 uv; //texture coordinates
		float tid;
		unsigned int color;
	};

	class RenderAble2D {
	protected:
		maths::vec3 m_Position;
		maths::vec2 m_Size;
		maths::vec4 m_Color;
		std::vector<maths::vec2> m_Uv;
		Texture* m_Texture;
	protected:
		RenderAble2D() { setUVdefaults();}

	public:
		RenderAble2D(maths::vec3 position, maths::vec2 size, maths::vec4 color)
			: m_Position(position), m_Size(size), m_Color(color) 
		{
			setUVdefaults();
		}

		virtual ~RenderAble2D() { }

		virtual void submit(Renderer2D* renderer) const {
			renderer->submit(this);
		}

		inline const maths::vec3& getPosition() const { return m_Position; }
		inline const maths::vec2& getSize() const { return m_Size; }
		inline const maths::vec4& getColor() const { return m_Color; }
		inline const std::vector<maths::vec2>& getUV() const { return m_Uv; }
		inline const GLuint getTID() const { return m_Texture == nullptr ? 0 : m_Texture->getID(); }

	private:
		void setUVdefaults() {
			m_Uv.push_back(maths::vec2(0, 0));
			m_Uv.push_back(maths::vec2(0, 1));
			m_Uv.push_back(maths::vec2(1, 1));
			m_Uv.push_back(maths::vec2(1, 0));
		}
	};


}}