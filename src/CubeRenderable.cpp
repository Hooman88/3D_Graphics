#include "./../include/CubeRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/CubeRenderable.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>



	CubeRenderable::CubeRenderable(ShaderProgramPtr shaderProgram)
	  : Renderable(shaderProgram),
	    m_pBuffer(0)
	{
	    //Build the geometry: just a simple triangle for now
	    m_positions.push_back(glm::vec3(-1,0,0));
	    m_positions.push_back(glm::vec3(1,0,0));
	    m_positions.push_back(glm::vec3(0,1,0));

	    //Set the model matrix to identity
	    m_model = glm::mat4(1.0);
		glGenBuffers(1, &m_pBuffer);

		//Bind the buffer to the GL_ARRAY_BUFFER binding point
		//This is a place to perform vertex attributes operations)
		glBindBuffer(GL_ARRAY_BUFFER, m_pBuffer);

		//Transfer data to our new buffer thanks to this binding point
		//This function resize the buffer to the requested side
		glBufferData(GL_ARRAY_BUFFER, m_positions.size()*sizeof(glm::vec3), m_positions.data(), GL_STATIC_DRAW);
             
	
	}

	void CubeRenderable::do_draw()
		{
	   	  //Get the identifier (location) of the uniform modelMat in the shader program
		   int modelLocation = m_shaderProgram->getUniformLocation("modelMat");
		    //Send the data corresponding to this identifier on the GPU
		    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(m_model));

		    //Get the identifier of the attribute vPosition in the shader program
		    int positionLocation = m_shaderProgram->getAttributeLocation("vPosition");
		    //Activate the attribute array at this location
		    glEnableVertexAttribArray(positionLocation);
		    //Bind the position buffer on the GL_ARRAY_BUFFER target
		    glBindBuffer(GL_ARRAY_BUFFER, m_pBuffer);
		    //Specify the location and the format of the vertex position attribute
		    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		    //Draw the triangles
		    glDrawArrays(GL_TRIANGLES,0, m_positions.size());

		    //Release the vertex attribute array
		    glDisableVertexAttribArray(positionLocation);
		}

void CubeRenderable::do_animate(float time)
{
}

  	CubeRenderable::~CubeRenderable()
		{
		    glDeleteBuffers(1, &m_pBuffer);
		}
			

