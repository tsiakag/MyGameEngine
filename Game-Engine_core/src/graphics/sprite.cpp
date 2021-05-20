#include "sprite.h"

namespace MyGameEngine { namespace graphics {

	Sprite::Sprite(float x, float y, float width, float height, const maths::vec4& color)
		: RenderAble2D(maths::vec3(x, y, 0), maths::vec2(width, height), color)
	{}

}}