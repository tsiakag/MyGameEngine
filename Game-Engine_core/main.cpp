#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"
#include "src/utilities/fileutils.h"

#include "src/graphics/buffer/buffer.h"
#include "src/graphics/buffer/indexbuffer.h"
#include "src/graphics/buffer/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/batchrenderer2d.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
//#include "src/utilities/timer.h"

#include "src/graphics/Layers/tilelayer.h"

#include "src/graphics/Layers/group.h"

#include <time.h>
#include "src/graphics/texture.h"
#include <iostream>

#define BATCH_RENDERER 1

#if 1
int main() {
	using namespace MyGameEngine;
	using namespace graphics;
	using namespace maths;


	Window window("MyBeautifulWindow", 960, 540);
	//glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	
	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));


	srand(time(NULL));
	
	TileLayer layer(&shader);
	for (float y = -9.0f; y < 9.0f; y ++)
		for (float x = -16.0f; x < 16.0f; x ++)
		layer.add(new Sprite(x, y, 0.9f, 0.9f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
	

	glActiveTexture(GL_TEXTURE0);
	Texture texture("test.png");
	texture.bind();

	GLint texIDs[]{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);
	shader.setUniformMat4("pr_matrix", maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	//Timer time;
	float timer = 0;
	int frames = 0;
	while (!window.Closed()) {

		window.Clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));

		layer.render(); 

		frames++;
		window.Update();
	/*if ((time.elapsed() - timer) > 1.0f) {
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}*/
	}

	return 0;
}
#endif

#if 0
int main() {

	const char* filename = "test.png";

	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//pointer to the image, once loaded
	FIBITMAP* dib(0);
	//pointer to the image data
	BYTE* bits(0);
	//image width and height
	unsigned int width(0), height(0);
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;

	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);
	//if the image failed to load, return failure
	if (!dib)
		return false;

	bits = FreeImage_GetBits(dib);
	unsigned int s = FreeImage_GetBPP(dib);
	unsigned int pitch = FreeImage_GetPitch(dib);

	//retrieve the image data
	bits = FreeImage_GetBits(dib);
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;

	for (int y = 0; y < height; y++) {
		BYTE* pixel = (BYTE*)bits;
		for (int x = 0; x < width; x++) {
			std::cout << +pixel[FI_RGBA_RED] << " " << +pixel[FI_RGBA_GREEN] << " " << +pixel[FI_RGBA_BLUE] << std::endl;
			pixel += 3;
		}
		bits += pitch;
	}
	FreeImage_Unload(dib);

	return 0;
}

#endif