#pragma once

#include <cstddef>
#include "renderer2d.h"
#include "renderable2d.h"
#include "buffer/indexbuffer.h"

namespace MyGameEngine { namespace graphics {
	
#define RENDERER_MAX_SPRITES   50000 // in case of no memory change it or indices from short to int
#define RENDERER_VERTEX_SIZE   sizeof(VertexData)
#define RENDERER_SPRITE_SIZE   RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE   RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE  RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_UV_INDEX 1
#define SHADER_TID_INDEX 2
#define SHADER_COLOR_INDEX 3

	class BatchRenderer2D : public Renderer2D {
	private:
		GLuint m_VAO;
		GLuint m_VBO;
		IndexBuffer* m_IBO;
		GLsizei m_IndexCount;
		VertexData* m_Buffer;

		std::vector<GLuint> m_TextureSlots;
	
	public:
		BatchRenderer2D();
		~BatchRenderer2D();

		void begin() override;
		void submit(const RenderAble2D* rendereable) override;
		void end() override;

		void flush() override;
	
	private:
		void init();
	};





}}