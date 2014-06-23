#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "renderer/Renderer.h"
#include "scene/WorldWindow.h"
#include "app/AppConfigurationFileReader.h"
#include "scene/SceneFactory.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include "shape/Player.h"

Renderer * renderer;
int nCols, nRows;
WorldWindow * worldWindow;
Player * player;

void reshape(int w, int h){
	double worldwindowRatio = worldWindow->getRatio();
	if(worldwindowRatio > w/h){
		glViewport(0, (h-w/worldwindowRatio)/2, w, w/worldwindowRatio);
	} else {
		glViewport((w-h*worldwindowRatio)/2,0,h*worldwindowRatio,h);
	}
}

void timer(int unused){
    glutPostRedisplay();
    glutTimerFunc(3,timer,0);
}


void renderScene(void){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(worldWindow->getLeft(), worldWindow->getRight(),
			   worldWindow->getBottom(), worldWindow->getTop());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_LIGHTING);
    renderer->render();
    glutSwapBuffers();
}
void OnMouseClick(int button, int state, int x, int y){
	player->setCenter(Point(x,y));
}

int main(int argc, char ** argv){
	AppConfiguration appCfg = AppConfigurationFileReader::read(argv[1]);
	nCols = std::atoi(appCfg["image.nCols"].c_str());
	nRows = std::atoi(appCfg["image.nRows"].c_str());
	worldWindow = new WorldWindow(std::atof(appCfg["worldwindow.left"].c_str()),
				std::atof(appCfg["worldwindow.right"].c_str()),
				std::atof(appCfg["worldwindow.bottom"].c_str()),
				std::atof(appCfg["worldwindow.top"].c_str()));
	Scene scene = SceneFactory::createScene(appCfg["scene.file"],*worldWindow);
	player = new Player(Colour(1,1,1));
	scene.addDrawable(player);
	renderer = new Renderer(scene);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(nCols, nRows);
	glutCreateWindow("Programmeren voor multimedia");
	glutDisplayFunc(renderScene);
	glutMouseFunc(OnMouseClick);
	glutReshapeFunc(reshape);
	timer(0);
	glutMainLoop();
	delete renderer;
	delete worldWindow;
	return 0;
}

