#include "stdafx.h"



#include "Camera.h"
#include "ShaderProgram.h"
#include "BasicRenderableObject.h"




/////////////////////////////////////////////////////////
// Variables globales pour la gestion de l'application //
/////////////////////////////////////////////////////////



int				g_width = 800;
int				g_height = 600;
int				centreX = g_width/2;
int				centreY = g_height/2;

float			g_PreviousXPosition;
float			g_PreviousYPosition;
bool			g_LeftButtonPressed;
bool			g_RightButtonPressed;

double			yAngle = 0.0;
double			xAngle = 0.0;
float			sensibilityX = .65f;
float			sensibilityY = .70f;

double			g_CurrentTime;
double			g_PreviousTime;

Camera*			g_Camera;

Light*			g_Light = new Light ();
Light*			g_Light2 = new Light ();

BasicRenderableObject*				g_Enterprise;
BasicRenderableObject*				g_Enterprise2;
BasicRenderableObject*				g_Church;
BasicRenderableObject*				g_Sky;

enum mode {CAMERA , ENTERPRISE , CHURCH} ; // Pour savoir quel objet on selectionne.
enum mode currentMode = CAMERA ; // Par defaut, l'ensemble de la scene.





///////////////////////////
// Fonctions auxiliaires //
///////////////////////////



void initialiseGLState()
{
	printGLErrors("initialiseGLState() start");

	glClearColor(0.75, 0.75, 0.75, 1.0);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	g_Camera = new Camera((float)g_width, (float)g_height);
	g_Light2 -> setPosition (-0.75 , 0.5 , 0. , 0.) ;
	g_Light2 -> setDiffuse (1 , 0. , 0.) ;

	printGLErrors("initialiseGLState() end");
}

void initialiseObjects()
{
	printGLErrors("initialiseObjects() start");

	// creation du VBO

	g_Enterprise = new BasicRenderableObject();
	g_Enterprise->initShader( ShaderProgram::createAmbientMapShader() );
	g_Enterprise->init();
	g_Enterprise->loadMtl("Models/USSEnterprise.mtl");
	g_Enterprise->loadObj("Models/USSEnterprise.obj");
	g_Enterprise->fillInVBO();
	g_Enterprise->createVertexArrayObject();
	
	
	
	//g_Enterprise -> rotateGlobalObject (90 , 0 , 1 , 0) ;
	

	g_Enterprise2 = new BasicRenderableObject();
	g_Enterprise2->initShader( ShaderProgram::createAmbientMapShader() );
	g_Enterprise2->init();
	g_Enterprise2->loadMtl("Models/USSEnterprise.mtl");
	g_Enterprise2->loadObj("Models/USSEnterprise.obj");
	g_Enterprise2->fillInVBO();
	g_Enterprise2->createVertexArrayObject();
	
	//g_Enterprise-> translateLocalObject(5, -1.5, 0);
	g_Enterprise -> rotateGlobalObject (90 , 0 , 1 , 0) ;
	

	g_Church = new BasicRenderableObject();
	g_Church->initShader(ShaderProgram::createAmbientMapShader());
	g_Church->init();
	g_Church->loadMtl("Models/sibenik_blenderexport.mtl");
	g_Church->loadObj("Models/sibenik_blenderexport.obj");
	g_Church->fillInVBO();
	g_Church->createVertexArrayObject();

	g_Sky = new BasicRenderableObject();
	g_Sky->initShader(ShaderProgram::createStdShader());
	g_Sky->init();
	g_Sky->loadMtl("Models/Environment5.mtl");
	g_Sky->loadObj("Models/Environment5.obj");
	g_Sky->fillInVBO();
	g_Sky->createVertexArrayObject();
	
	g_Enterprise2 -> setParent (g_Enterprise) ;

	g_Enterprise-> translateGlobalObject(0, 0, 30);
	g_Enterprise2->translateLocalObject(10, 10, -10);
	
	printGLErrors("initialiseObjects() end");
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	g_CurrentTime = glfwGetTime();
	
	g_Enterprise->draw(g_Enterprise -> getModelMatrix () , g_Camera->GetViewMatrix(), g_Camera->GetProjectionMatrix() , g_Light);
	g_Enterprise2->draw(g_Enterprise2 -> getModelMatrix () , g_Camera->GetViewMatrix(), g_Camera->GetProjectionMatrix() , g_Light);
	g_Church->draw(g_Church -> getModelMatrix () , g_Camera->GetViewMatrix(), g_Camera->GetProjectionMatrix() , g_Light);
	g_Sky->draw(g_Church -> getModelMatrix () , g_Camera->GetViewMatrix(), g_Camera->GetProjectionMatrix() , g_Light);
			
	// TEST DU GRAPHE DE SCENE !
	//g_Enterprise-> translateGlobalObject(0, 0, -30);
	
	//g_Enterprise-> translateGlobalObject(0, 0, -30);
	g_Enterprise -> rotateGlobalObject (0.1 , 1 , 0.0 , 0.0) ;
	//g_Enterprise-> translateGlobalObject(0, 0, 30);
	//g_Enterprise->translateGlobalObject(0, 1.5, 0);

	g_PreviousTime = g_CurrentTime;

	printGLErrors("Error during drawing");
}

void resize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
	g_Camera->UpdateProjectionMatrix((float)width, (float)height);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ((key == GLFW_KEY_E) && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		currentMode = ENTERPRISE ;
	}
	else if ((key == GLFW_KEY_C) && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		currentMode = CHURCH ;
	}
	else if ((key == GLFW_KEY_A) && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		currentMode = CAMERA ;
	}
	else if(key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (currentMode == CAMERA)
		{
			g_Camera->translateLocal(0.0f, 0.0f, 1.0f);
		}
		else if (currentMode == ENTERPRISE)
		{
			g_Enterprise->translateLocalObject(0.0f, 0.0f, 1.0f);
		}
		else if (currentMode == CHURCH)
		{
			g_Church->translateLocalObject(0.0f, 0.0f, 1.0f);
		}
	}
	if(key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (currentMode == CAMERA)
		{
			g_Camera->translateLocal(0.0f, 0.0f, -1.0f);
		}
		else if (currentMode == ENTERPRISE)
		{
			g_Enterprise->translateLocalObject(0.0f, 0.0f, -1.0f);
		}
		else if (currentMode == CHURCH)
		{
			g_Church->translateLocalObject(0.0f, 0.0f, -1.0f);
		}
	}
	if(key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (currentMode == CAMERA)
		{
			g_Camera->translateLocal(1.0f, 0.0f, 0.0f);
		}
		else if (currentMode == ENTERPRISE)
		{
			g_Enterprise->translateLocalObject(1.0f, 0.0f, 0.0f);
		}
		else if (currentMode == CHURCH)
		{
			g_Church->translateLocalObject(1.0f, 0.0f, 0.0f);
		}
	}
	if(key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (currentMode == CAMERA)
		{
			g_Camera->translateLocal(-1.0f, 0.0f, 0.0f);
		}
		else if (currentMode == ENTERPRISE)
		{
			g_Enterprise->translateLocalObject(-1.0f, 0.0f, 0.0f);
		}
		else if (currentMode == CHURCH)
		{
			g_Church->translateLocalObject(-1.0f, 0.0f, 0.0f);
		}
	}

	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void mouseButton_callback(GLFWwindow* window, int button, int action, int mods)
{
	if(button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if(action == GLFW_PRESS)
		{
			g_LeftButtonPressed = !g_LeftButtonPressed;
			glfwSetCursorPos(window , centreX , centreY);
		}
		
	}

	if(button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if(action == GLFW_PRESS)
		{
			g_RightButtonPressed = true;
		}
		else if(action == GLFW_RELEASE)
		{
			g_RightButtonPressed = false;
		}
	}
}

void mouseMove_callback(GLFWwindow* window, double x, double y)
{
	
	if(g_LeftButtonPressed)
	{		
		// on enleve la rotation sur Y pour appliquer la rotation horizontale a plat.
		g_Camera->rotateLocal((float)yAngle * -0.5f, 1.0f, 0.0f, 0.0f);		
		
		yAngle = yAngle + (y - centreY)* sensibilityY;
		xAngle = (x - centreX) * sensibilityX;


		g_Camera->rotateLocal((float)xAngle * 0.5f, 0.0f, 1.0f, 0.0f);
		g_Camera->rotateLocal((float)yAngle * 0.5f, 1.0f, 0.0f, 0.0f);

		glfwSetCursorPos(window , g_width/2 , g_height/2);
	}
}



//////////
// Main //
//////////



int main(int argc, char* argv[])
{
	GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(g_width, g_height, "OpenGL Window", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, resize);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouseMove_callback);
	glfwSetMouseButtonCallback(window, mouseButton_callback);

	// Initialize GLEW
	glewExperimental = GL_TRUE; 

	GLenum err = glewInit();

	if(GLEW_OK != err)
	{
		std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
	}
	else
	{
		if (GLEW_VERSION_3_3)
		{
			std::cout << "Driver supports OpenGL 3.3" << std::endl;

			std::cout << "Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
			std::cout << "Vendor: " << glGetString (GL_VENDOR) << std::endl;
			std::cout << "Renderer: " << glGetString (GL_RENDERER) << std::endl;
			std::cout << "Version: " << glGetString (GL_VERSION) << std::endl;
			std::cout << "GLSL: " << glGetString (GL_SHADING_LANGUAGE_VERSION) << std::endl;
		}
	}

	// Initialize our GL state
	initialiseGLState();

	// Create and initialize the objets in the scene
	initialiseObjects();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        
		

		/* Render here */
		display();
		

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
