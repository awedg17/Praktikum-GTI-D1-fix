#include <GL/glut.h>
#include <stdlib.h>

int shoulder = 0, elbow = 0;

int f1a=0,f1b=0;
int f2a=0,f2b=0;
int f3a=0,f3b=0;
int f4a=0,f4b=0;
int f5a=0,f5b=0;

void init(void){
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);
}

void drawFinger(int a, int b, float y){
    glPushMatrix();

        glTranslatef(0.8, y, 0);

        // ruas jari 1
        glRotatef(a,0,0,1);
        glPushMatrix();
            glTranslatef(0.4,0,0);
            glScalef(0.8,0.12,0.2);
            glutWireCube(1);
        glPopMatrix();

        glTranslatef(0.8,0,0);

        // ruas jari 2
        glRotatef(b,0,0,1);
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glScalef(0.6,0.1,0.2);
            glutWireCube(1);
        glPopMatrix();

    glPopMatrix();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // bahu
    glTranslatef(-2,0,0);
    glRotatef(shoulder,0,0,1);
    glTranslatef(2,0,0);

    glPushMatrix();
        glScalef(4,0.4,1);
        glutWireCube(1);
    glPopMatrix();

    // siku
    glTranslatef(2,0,0);
    glRotatef(elbow,0,0,1);
    glTranslatef(2,0,0);

    glPushMatrix();
        glScalef(4,0.4,1);
        glutWireCube(1);
    glPopMatrix();

	glTranslatef(1.2,0,0);

    // telapak
    glPushMatrix();
        glScalef(1.5,0.8,0.6);
        glutWireCube(1);
    glPopMatrix();

    // jari
    drawFinger(f1a,f1b, 0.3);
    drawFinger(f2a,f2b, 0.15);
    drawFinger(f3a,f3b, 0.0);
    drawFinger(f4a,f4b,-0.15);
    drawFinger(f5a,f5b,-0.3);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w,int h){
    if(h==0) h=1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65,(float)w/h,1,20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-10);
}

void keyboard(unsigned char key,int x,int y){
    switch(key){

	case 's': shoulder += 5; break;
	case 'S': shoulder -= 5; break;
	
	case 'd': elbow += 5; break;
	case 'D': elbow -= 5; break;
	
	// ibu jari
	case 'q': f1a += 5; break;
	case 'Q': f1a -= 5; break;
	case 'w': f1b += 5; break;
	case 'W': f1b -= 5; break;
	
	// telunjuk
	case 'e': f2a += 5; break;
	case 'E': f2a -= 5; break;
	case 'r': f2b += 5; break;
	case 'R': f2b -= 5; break;
	
	// jari tengah
	case 't': f3a += 5; break;
	case 'T': f3a -= 5; break;
	case 'y': f3b += 5; break;
	case 'Y': f3b -= 5; break;
	
	// jari manis
	case 'u': f4a += 5; break;
	case 'U': f4a -= 5; break;
	case 'i': f4b += 5; break;
	case 'I': f4b -= 5; break;
	
	// kelingking
	case 'o': f5a += 5; break;
	case 'O': f5a -= 5; break;
	case 'p': f5b += 5; break;
	case 'P': f5b -= 5; break;

   	case 27: exit(0);
    }

    glutPostRedisplay();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

    glutInitWindowSize(700,600);
    glutCreateWindow("Tugas");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
