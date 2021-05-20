#include "window.h"
#include <iostream>
#include <GLFW/glfw3.h>

namespace MyGameEngine {
	namespace graphics {

		void Window_resize(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		Window::Window(const char* name, int width, int height) {
			m_name = name;
			m_width = width;
			m_height = height;
			
			if(!init())
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; i++) m_keys[i] = false;
			for (int i = 0; i < MAX_BUTTONS; i++) m_mousebuttons[i] = false;
		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Error" << std::endl;
				return false;
			}
			else
				std::cout << "Success" << std::endl;

			m_window = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);
			
			if (!m_window) {
				glfwTerminate();
				std::cout << "Failed to create window" << std::endl;
			}

					
			glfwMakeContextCurrent(m_window); //can create context in this window
			glfwSetWindowUserPointer(m_window, this);
			glfwSetWindowSizeCallback(m_window, Window_resize); //calls the window resize function
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, cursor_position_callback);

			std::cout << glGetString(GL_VERSION) << std::endl;

			if (glewInit() != GLEW_OK) {
				std::cout << "Could not init GLEW" << std::endl;
				return false;
			} //checks if glue is init

			return true;	
		}

		bool Window::Closed() const {
			return glfwWindowShouldClose(m_window) == 1; //int == int
		}

		void Window::Update(){
			GLenum error = glGetError();
			if (error != GL_NO_ERROR) {
				std::cout << "OpenGL Error:" << error << std::endl;
			}

			glfwPollEvents();
			glfwGetFramebufferSize(m_window, &m_width, &m_height);
			glfwSwapBuffers(m_window);

		}

		bool Window::isKeyPressed(unsigned int keycode) const{

			if (keycode >= MAX_KEYS)
				return false;

			return m_keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const{

			if (button >= MAX_BUTTONS)
				return false;

			return m_mousebuttons[button];
		}

		void Window::getMousePosition(double& x, double& y) const{
			x = mx;
			y = my;
		}

		void Window::Clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window_resize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			
			win->m_keys[key] = action != GLFW_RELEASE;
		}
		
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			
			win->m_mousebuttons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);

			win->mx = xpos;
			win->my = ypos;
		}

	}
}