#include "stdafx.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include "glut.h"  

#define WIDTH  480
#define HEIGHT 480
 
#define RED   0
#define GREEN 0
#define BLUE  0
#define ALPHA 1
#define PI 3.14159
 
#define KEY_ESC 27
 
void init_scene();
void render_scene();
GLvoid initGL();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height); 
GLvoid window_key(unsigned char key, int x, int y); 
GLvoid window_idle(); 
 
static double zRotate = 0.5;
static double facteur = 0.5;

int main(int argc, char **argv) 
{  
  // initialisation  des paramètres de GLUT en fonction
  // des arguments sur la ligne de commande
  glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // définition et création de la fenêtre graphique
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Primitives graphiques");
 
  // initialisation de OpenGL et de la scène
  initGL();  
  init_scene();
 
  // choix des procédures de callback pour 
  // le tracé graphique
  glutDisplayFunc(&window_display);
  // le redimensionnement de la fenêtre
  glutReshapeFunc(&window_reshape);
  // la gestion des événements clavier
  glutKeyboardFunc(&window_key);
  glutIdleFunc(&window_idle);
  // la boucle prinicipale de gestion des événements utilisateur
  glutMainLoop();  
 
  return 1;
}
 
// initialisation du fond de la fenêtre graphique : noir opaque
 
GLvoid initGL() 
{
        glShadeModel(GL_SMOOTH);
    glClearColor(RED, GREEN, BLUE, ALPHA);
        glEnable(GL_DEPTH_TEST);
}
 
void init_scene()
{
}
 
void theiereAligne()
{
	glPushMatrix();
		glTranslated(0.0,-5,0.0);
		glRotated(20,0.0,0.0,1.0);
		glPushMatrix();
			glRotated(zRotate*5.5,0.0,1.0,0.0);
			glTranslated(5.5,2.0,0.0);
			glColor3f (0.0, 1.0, 0.0);
			glutWireSphere (0.5, 10, 10);
		glPopMatrix();
		glRotated(zRotate*5,0.0,1.0,0.0);
		glColor3f (1.0, 1.0, 1.0);
		glutWireTeapot(3);
	glPopMatrix();


	glPushMatrix();
		glTranslated(0.0,-1,0.0);
		glRotated(20,0.0,0.0,1.0);
		glPushMatrix();
			glRotated(zRotate*1.5,0.0,1.0,0.0);
			glTranslated(3.5,1.5,0.0);
			glColor3f (1.0, 0.0, 0.0);
			glutWireSphere (0.4, 10, 10);
		glPopMatrix();
		glRotated(zRotate*1,0.0,1.0,0.0);
		glColor3f (1.0, 1.0, 1.0);
		glutWireTeapot(2);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0.0,1.5,0.0);
		glRotated(20,0.0,0.0,1.0);
		glPushMatrix();
			glRotated(zRotate*2.0,0.0,1.0,0.0);
			glTranslated(2.0,1.0,0.0);
			glColor3f (0.0, 0.0, 1.0);
			glutWireSphere (0.3, 10, 10);
		glPopMatrix();
		glRotated(zRotate*1.5,0.0,1.0,0.0);
		glColor3f (1.0, 1.0, 1.0);
		glutWireTeapot(1);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0.0,2.75,0.0);
		glRotated(20,0.0,0.0,1.0);
		glPushMatrix();
			glRotated(zRotate*3.25,0.0,1.0,0.0);
			glTranslated(1.0,0.5,0.0);
			glColor3f (1.0, 0.0, 1.0);
			glutWireSphere (0.2, 10, 10);
		glPopMatrix();
		glRotated(zRotate*2.75,0.0,1.0,0.0);
		glColor3f (1.0, 1.0, 1.0);
		glutWireTeapot(0.5);
	glPopMatrix();
}

void theiereAligneBoucle()
{
	glPushMatrix();
	glRotated(20,0.0,0.0,1.0);
	for(int i = 5; i > 1; i--)
	{
		glPushMatrix();

			//rotation autour de l'axe
			glRotated(zRotate*i,0.0,1.0,0.0);
			glTranslated(2,0.0,0.0);

			// rotation autour d'elle meme
			glTranslated(0.0,-i*(i-3),0.0);
			glPushMatrix();
				glRotated(zRotate*i,0.0,1.0,0.0);
				glutWireTeapot(i-1);
			glPopMatrix();

			//rotation boule
			glPushMatrix();
				glRotated(zRotate*(-i*2),0.0,1.0,0.0);
				glTranslated(i+0.5,i/2,0.0);
				glutWireSphere (i*0.1, 10, 10);
			glPopMatrix();
		
		glPopMatrix();

	}
	glPopMatrix();
}


// fonction de call-back pour l´affichage dans la fenêtre
GLvoid window_display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
  render_scene();
  //theiereAligne();

  theiereAligneBoucle();
  // trace la scène grapnique qui vient juste d'être définie
  glFlush();
  glutSwapBuffers();
  
}
 
// fonction de call-back pour le redimensionnement de la fenêtre
 
GLvoid window_reshape(GLsizei width, GLsizei height)
{  
  glViewport(0, 0, width, height);
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
 
  // toutes les transformations suivantes s´appliquent au modèle de vue 
  glMatrixMode(GL_MODELVIEW);
}
 
// fonction de call-back pour la gestion des événements clavier
 
GLvoid window_key(unsigned char key, int x, int y) 
{  
  switch (key) {    
  case KEY_ESC:  
    exit(1);                    
    break;
     

  default:
    printf ("La touche %d n´est pas active.\n", key);
    break;
  }     
}
 
GLvoid window_idle() 
{  
	zRotate+=facteur;
	glutPostRedisplay();
}
 
 
void render_scene()
{
//c'est ici qu'on dessine
    //glLoadIdentity();
 
 
 }