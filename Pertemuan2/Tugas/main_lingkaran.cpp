#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <math.h>

void gambarLingkaran(float radius, int jumlahTitik) {
    glBegin(GL_LINE_LOOP);   
    for (int i = 0; i < jumlahTitik; i++) {
        float sudut = 2.0f * 3.1415926f * i / jumlahTitik;
        float x = radius * cos(sudut);
        float y = radius * sin(sudut);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f); 
    gambarLingkaran(0.5f, 100);

    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lingkaran");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
