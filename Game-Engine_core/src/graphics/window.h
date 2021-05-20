#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace MyGameEngine { namespace graphics {

	class Window {
	public:
		static Window* INSTANCE;
	public:
		Window(const char* name, int width, int height);
		~Window();

		void Update();
		bool Closed() const;
		void Clear() const;
	
		inline int GetWidth() const { return m_width; }
		inline int GetHeight() const{ return m_height; }

		bool isKeyPressed(unsigned int keycode) const;
		bool isMouseButtonPressed(unsigned int button) const;
		void getMousePosition(double& x, double& y) const;
	private:
		//window parameters
		const char* m_name; 
		int m_width, m_height;
		bool m_closed;
		GLFWwindow* m_window;

		//input variables
		bool m_keys[MAX_KEYS];
		bool m_mousebuttons[MAX_BUTTONS];
		double mx, my; //mouse cord

		bool init(); //for checking in the intializer

		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};




 } }
