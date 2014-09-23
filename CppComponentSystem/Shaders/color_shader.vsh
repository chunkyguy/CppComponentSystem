/* render a color to a quad */

attribute vec4 av4o_Position;
uniform mat4 um4k_Modelviewprojection;

void main()
{
    gl_Position = um4k_Modelviewprojection * av4o_Position;
}

