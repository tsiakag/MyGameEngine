#pragma once

#include "../renderable2d.h"
#include "../renderer2d.h"

namespace MyGameEngine {namespace graphics {

	class Layer {
	protected:
		Renderer2D* m_Renderer;
		std::vector<RenderAble2D*> m_Renderables;
		Shader* m_Shader;
		maths::mat4 m_ProjectionMatrix;

	public:
		Layer();
		virtual ~Layer();
		virtual void add(RenderAble2D* renderable);
		virtual void render();

	protected:
		Layer(Renderer2D* renderer, Shader* shader, maths::mat4 projectionMatrix);

	};



}}