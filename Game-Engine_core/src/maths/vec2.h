#pragma once
#include <iostream>

namespace MyGameEngine { namespace maths {

	struct vec2 {
		float x, y;

		//contructors
		vec2(); //default constructor
		vec2(const float& x, const float& y);

		vec2& add(const vec2& other);
		vec2& subtract(const vec2& other);
		vec2& multiply(const vec2& other);
		vec2& divide(const vec2& other);

		//dont use vec2& a = b + c!!!!!
		//use of friend in not required since the functions are public
		friend vec2& operator+ (vec2 left, const vec2& right);
		friend vec2& operator- (vec2 left, const vec2& right);
		friend vec2& operator* (vec2 left, const vec2& right);
		friend vec2& operator/ (vec2 left, const vec2& right);

		bool operator== (const vec2& other);
		bool operator!= (const vec2& other);

		vec2& operator+= (const vec2& other);
		vec2& operator-= (const vec2& other);
		vec2& operator*= (const vec2& other);
		vec2& operator/= (const vec2& other);

		friend std::ostream& operator<< (std::ostream&, const vec2& vector);

	};











} }