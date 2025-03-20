#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>
using namespace std;

GLFWwindow* StartGLFW();

float screenHeight = 600.0f;
float screenWidth = 800.0f;

int main(){
    GLFWwindow* window= StartGLFW();

    float centreX = screenWidth / 2.0f;
    float centreY = screenHeight / 2.0f;
    float radius = 50.0f;
    int resolution = 100;


    while (!glfwWindowShouldClose(window)){ // main window loop
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(centreX,centreY);

        for (int i=0; i<= resolution; ++i)
        {
            float angle = 2.0f * 3.14159 * (static_cast<float>(i)/resolution);
            float x = centreX + cos(angle) * radius;
            float y = centreY + sin(angle) * radius;
            glVertex2d(x , y);

        }

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

    }


}

GLFWwindow* StartGLFW(){
    if(!glfwInit())
    {
        cout << "Unable to initialize glfw" << endl;
        return nullptr;
    }

    GLFWwindow* window = glfwCreateWindow(800,600,"Gravity Simulation",NULL,NULL);
    return window;
}
