#include "./../include/CylinderRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/Utils.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>

CylinderRenderable::CylinderRenderable(ShaderProgramPtr shaderProgram) :
    Renderable(shaderProgram),
    m_pBuffer(0), m_cBuffer(0)
{
    // Here you must:
    // 1. define the positions and colors of all your vertices
    //    (you might stored them in m_positions and m_colors)
    // 2. generate gl buffers,
    // 3. for each of them, bind then send data
    //
    // No code is provided, let's see if you're getting
    // more comfortable (or not) with these different steps
    //
    // For step 1, ask yourself how many vertices you want, are they
    // shared or not by multiple triangles, how to compute their position, ...
    // Indexing is more difficult, you may start with direct generation first

}

CylinderRenderable::~CylinderRenderable()
{
    glcheck(glDeleteBuffers(1, &m_pBuffer));
    glcheck(glDeleteBuffers(1, &m_cBuffer));
}

void CylinderRenderable::do_draw()
{
    // Here you must:
    // 1. get the model matrix and send it to the shader (as uniform)
    // 2. for each attribute: retrieve its location on the shader,
    //    activate it, bind a buffer, then specify internal format
    // 3. draw the triangles
    // 4. unbind everything

}

void CylinderRenderable::do_animate(float time)
{
}
