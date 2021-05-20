#pragma once
// iniefecient method
#include <deque>
#include "static_sprite.h"
#include "renderer2d.h"


namespace MyGameEngine { namespace graphics {
	
	class Simple2DRenderer : public Renderer2D {
	private:
		std::deque<const StaticSprite*> m_RenderQueue;

	public:
		 void submit(const RenderAble2D* renderable) override;
		 void flush() override;
	};

}}