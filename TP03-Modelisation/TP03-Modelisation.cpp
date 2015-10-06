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
  // initialisation  des param�tres de GLUT en fonction
  // des arguments sur la ligne de commande
  glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // d�finition et cr�ation de la fen�tre graphique
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Primitives graphiques");
 
  // initialisation de OpenGL et de la sc�ne
  initGL();  
  init_scene();
 
  // choix des proc�dures de callback pour 
  // le trac� graphique
  glutDisplayFunc(&window_display);
  // le redimensionnement de la fen�tre
  glutReshapeFunc(&window_reshape);
  // la gestion des �v�nements clavier
  glutKeyboardFunc(&window_key);
  glutIdleFunc(&window_idle);
  // la boucle prinicipale de gestion des �v�nements utilisateur
  glutMainLoop();  
 
  return 1;
}
 
// initialisation du fond de la fen�tre graphique : noir opaque
 
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


// fonction de call-back pour l�affichage dans la fen�tre
GLvoid window_display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
  render_scene();
  //theiereAligne();

  theiereAligneBoucle();
  // trace la sc�ne grapnique qui vient juste d'�tre d�finie
  glFlush();
  glutSwapBuffers();
  
}
 
// fonction de call-back pour le redimensionnement de la fen�tre
 
GLvoid window_reshape(GLsizei width, GLsizei height)
{  
  glViewport(0, 0, width, height);
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
 
  // toutes les transformations suivantes s�appliquent au mod�le de vue 
  glMatrixMode(GL_MODELVIEW);
}
 
// fonction de call-back pour la gestion des �v�nements clavier
 
GLvoid window_key(unsigned char key, int x, int y) 
{  
  switch (key) {    
  case KEY_ESC:  
    exit(1);                    
    break;
     

  default:
    printf ("La touche %d n�est pas active.\n", key);
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