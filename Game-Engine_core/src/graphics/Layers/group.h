#pragma once

#include"../renderable2d.h"

namespace MyGameEngine {
	namespace graphics {

		class Group : public RenderAble2D {
		private:
			std::vector<RenderAble2D*> m_Renderables;
			maths::mat4 m_TransformationMatrix;
		public:
			Group(const maths::mat4& transform);
			void add(RenderAble2D* renderable);
			void submit(Renderer2D* renderer) const override;



	};



}}