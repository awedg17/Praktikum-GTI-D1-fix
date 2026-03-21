#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void lingkaran(float r, float cx, float cy){
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++)
    {
        float a = 2 * PI * i / 100;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ===== LANGIT =====
    glColor3f(0.05,0.05,0.15);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.2);
        glVertex2f( 1,-0.2);
        glVertex2f( 1, 1);
        glVertex2f(-1, 1);
    glEnd();

    // ===== BINTANG =====
    glColor3f(1,1,1);

    glPointSize(1);
    glBegin(GL_POINTS);
        float bx[] = {
            -0.95,-0.9,-0.85,-0.75,-0.65,-0.55,-0.45,-0.35,-0.25,-0.15,
            -0.05,0.05,0.15,0.25,0.35,0.45,0.55,0.65,0.75,0.85,0.95
        };
        float by[] = {
            0.9,0.82,0.75,0.88,0.8,0.7,0.92,0.78,0.85,0.74,
            0.9,0.76,0.83,0.72,0.88,0.77,0.81,0.73,0.9,0.8,0.85
        };
        for(int i=0;i<21;i++) glVertex2f(bx[i],by[i]);
    glEnd();

    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2f(-0.8,0.85);
        glVertex2f(-0.4,0.78);
        glVertex2f(0.0,0.82);
        glVertex2f(0.4,0.75);
        glVertex2f(0.7,0.83);
    glEnd();

    // ===== BULAN =====
    glColor3f(1,1,0.6);
    lingkaran(0.07, -0.75, 0.88);

    // ===== GEDUNG =====
    float x[] = {-0.95,-0.78,-0.52,-0.25,0.0,0.28,0.5,0.78};
    float w[] = {0.15,0.2,0.18,0.22,0.17,0.21,0.16,0.2};
    float h[] = {0.3,0.55,0.4,0.25,0.55,0.45,0.3,0.55};

    for(int i=0;i<8;i++)
    {
        glColor3f(0.1,0.1,0.2);
        glBegin(GL_QUADS);
            glVertex2f(x[i], -0.2);
            glVertex2f(x[i]+w[i], -0.2);
            glVertex2f(x[i]+w[i], -0.2 + h[i]);
            glVertex2f(x[i], -0.2 + h[i]);
        glEnd();
    }

    // ===== SEMAK =====
    glColor3f(0,0.4,0);
    for(float i=-1;i<1;i+=0.17)
        lingkaran(0.07, i, -0.22);

    // ===== TROTOAR =====
    glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.25);
        glVertex2f(1,-0.25);
        glVertex2f(1,-0.33);
        glVertex2f(-1,-0.33);
    glEnd();

    // ===== JALAN =====
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.33);
        glVertex2f(1,-0.33);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();

    glColor3f(1,1,1);
    for(float i=-0.9;i<1;i+=0.3)
    {
        glBegin(GL_QUADS);
            glVertex2f(i,-0.6);
            glVertex2f(i+0.15,-0.6);
            glVertex2f(i+0.15,-0.57);
            glVertex2f(i,-0.57);
        glEnd();
    }

    // ===== MOBIL =====
    glPushMatrix();
    glTranslatef(0,-0.47,0); 
    
    // body
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-0.25,0);
        glVertex2f(0.25,0);
        glVertex2f(0.25,0.14);
        glVertex2f(-0.25,0.14);
    glEnd();

    // atap
    glBegin(GL_POLYGON);
        glVertex2f(-0.12,0.14);
        glVertex2f(0.12,0.14);
        glVertex2f(0.05,0.26);
        glVertex2f(-0.08,0.26);
    glEnd();

    // kaca
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.1,0.15);
        glVertex2f(0.1,0.15);
        glVertex2f(0.04,0.24);
        glVertex2f(-0.07,0.24);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.1,0.15);
        glVertex2f(0.1,0.15);
        glVertex2f(0.04,0.24);
        glVertex2f(-0.07,0.24);
    glEnd();

    // lampu depan
    glColor3f(1,1,0);
    lingkaran(0.02, 0.26, 0.07);

    // lampu belakang
    glColor3f(0.6,0,0);
    lingkaran(0.02, -0.26, 0.07);

    // roda
    glColor3f(0,0,0);
    lingkaran(0.07,-0.15,-0.02);
    lingkaran(0.07, 0.15,-0.02);

    glColor3f(0.7,0.7,0.7);
    lingkaran(0.04,-0.15,-0.02);
    lingkaran(0.04, 0.15,-0.02);

    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(700,700);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Mobil 2D");

    glutDisplayFunc(display);
    glClearColor(0,0,0,1);

    glutMainLoop();
    return 0;
}
