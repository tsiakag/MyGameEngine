#pragma once

#include "renderable2d.h"

namespace MyGameEngine {namespace graphics {

	class StaticSprite : public RenderAble2D {
	private:
		Shader& m_Shader;
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;

	public:
		StaticSprite(float x, float y, float width, float height, const maths::vec4 color, Shader& shader);
		~StaticSprite();

		inline const VertexArray* getVAO() const { return m_VertexArray;}
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer;}

		inline Shader& getShader() const { return m_Shader; }


	};




}}