#include <GL/glut.h>

void cube(float x,float y,float s)
{
    glBegin(GL_QUADS);

    glVertex2f(x,y);
    glVertex2f(x+s,y);
    glVertex2f(x+s,y+s);
    glVertex2f(x,y+s);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // TRIANGLE FAN (kiri atas)
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(-0.55,0.45);
    glVertex2f(-0.45,0.50);
    glVertex2f(-0.35,0.40);
    glVertex2f(-0.45,0.30);
    glVertex2f(-0.55,0.35);

    glEnd();

    // TRIANGLE STRIP (kanan atas)
    glBegin(GL_TRIANGLE_STRIP);

    glVertex2f(0.3,0.35);
    glVertex2f(0.4,0.55);
    glVertex2f(0.5,0.35);
    glVertex2f(0.6,0.55);

    glEnd();

    // KUBUS BERTINGKAT (TENGAH)
    float s = 0.1;
    float gap = 0.02;

    cube(-0.15,-0.1,s);
    cube(-0.15+s+gap,-0.1,s);
    cube(-0.15+2*(s+gap),-0.1,s);

    cube(-0.10,-0.1+s,s);
    cube(-0.10+s+gap,-0.1+s,s);

    cube(-0.05,-0.1+2*s,s);

    // QUAD STRIP (kiri bawah)
    glBegin(GL_QUAD_STRIP);

    glVertex2f(-0.6,-0.3);
    glVertex2f(-0.6,-0.2);
    glVertex2f(-0.45,-0.3);
    glVertex2f(-0.45,-0.2);
    glVertex2f(-0.3,-0.3);
    glVertex2f(-0.3,-0.2);

    glEnd();

    // LINE LOOP (kanan tengah)
    glBegin(GL_LINE_LOOP);

    glVertex2f(0.35,0.0);
    glVertex2f(0.55,0.0);
    glVertex2f(0.55,0.2);
    glVertex2f(0.35,0.2);

    glEnd();

    // LINE STRIP (bawah tengah)
    glBegin(GL_LINE_STRIP);

    glVertex2f(-0.2,-0.4);
    glVertex2f(-0.1,-0.3);
    glVertex2f(0.0,-0.4);
    glVertex2f(0.1,-0.3);
    glVertex2f(0.2,-0.4);

    glEnd();


    // QUADS (KANAN BAWAH)
    glBegin(GL_QUADS);

    glVertex2f(0.35,-0.35);
    glVertex2f(0.55,-0.35);
    glVertex2f(0.55,-0.15);
    glVertex2f(0.35,-0.15);

    glEnd();


    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);

    glutCreateWindow("Tugas");

    glutDisplayFunc(display);

    glClearColor(0,0,0,1);

    glutMainLoop();
}
