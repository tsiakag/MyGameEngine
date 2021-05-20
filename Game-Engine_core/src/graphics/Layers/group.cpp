#include "group.h"

namespace MyGameEngine { namespace graphics {

	Group::Group(const maths::mat4& transform) 
	: m_TransformationMatrix(transform) {}

	void Group::add(RenderAble2D* renderable){
		m_Renderables.push_back(renderable);
	}
	
	void Group::submit(Renderer2D* renderer) const{
		renderer->push(m_TransformationMatrix);

		for (const RenderAble2D* renderable : m_Renderables)
			renderable->submit(renderer);

		renderer->pop();
	}





} }