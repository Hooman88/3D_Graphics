#include "../include/Viewer.hpp"
#include "../include/log.hpp"
#include "./../include/Viewer.hpp"
#include "./../include/ShaderProgram.hpp"
#include "./../include/FrameRenderable.hpp"
#include "./../include/CubeRenderable.hpp"
	
#include <iostream>

static void initialize_scene (Viewer& viewer)
{
    // Path to the vertex shader glsl code
	std::string vShader = "./../shaders/defaultVertex.glsl";
	// Path to the fragment shader glsl code
	std::string fShader = "./../shaders/defaultFragment.glsl";
	// Compile and link the shaders into a program
	ShaderProgramPtr defaultShader = std::make_shared<ShaderProgram>(vShader, fShader);
	// Add the shader program to the Viewer
	viewer.addShaderProgram(defaultShader);
   	 std::cout << "Hello World!" << std::endl;

	  
	
	     
	FrameRenderablePtr frame = std::make_shared<FrameRenderable>(defaultShader);
	viewer.addRenderable(frame);

vShader = "./../shaders/flatVertex.glsl";
fShader = "./../shaders/flatFragment.glsl";
ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(vShader, fShader);

//Add the shader to the Viewer
viewer.addShaderProgram(flatShader);

    //Instanciate a CubeRenderable while specifying its shader program
    CubeRenderablePtr cube = std::make_shared<CubeRenderable>(flatShader);

    //Add the renderable to the Viewer
    viewer.addRenderable(cube);
}

int main()
{

	int width=1280; //Width of the window (pixel)
	int height=720; //Height of the window (pixel)
	Viewer viewer(width, height);
	
initialize_scene (viewer);

	while (viewer.isRunning()) {
   		 viewer.handleEvent();
   		 viewer.draw();
 	 	  viewer.display();
	}
	
   
   	 return EXIT_SUCCESS;
}
