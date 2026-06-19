#include <GL/glut.h>
#include <math.h>

void lingkaran(float cx, float cy, float r, int jumlahTitik) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < jumlahTitik; i++) {
        float sudut = 2.0f * 3.1415926f * i / jumlahTitik;
        float x = cx + r * cos(sudut);
        float y = cy + r * sin(sudut);
        glVertex2f(x, y);
    }
    glEnd();
}

void kotak(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void segitiga(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void background() {
    // langit
    glColor3f(0.55f, 0.82f, 1.0f);
    kotak(-300, 0, 300, 250);

    // tanah
    glColor3f(0.0f, 0.7f, 0.0f);
    kotak(-300, -120, 300, 0);

    // jalan
    glColor3f(0.2f, 0.2f, 0.2f);
    kotak(-300, -170, 300, -90);

    // garis jalan
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int x = -280; x < 300; x += 100) {
        kotak(x, -135, x + 50, -125);
    }

    // matahari
    glColor3f(1.0f, 0.9f, 0.0f);
    lingkaran(220, 180, 30, 80);

    // gunung
    glColor3f(0.25f, 0.45f, 0.28f);
    segitiga(-300, 0, -180, 130, -60, 0);
    segitiga(-80, 0, 60, 160, 200, 0);
    segitiga(100, 0, 220, 120, 320, 0);
}

void roda(float x, float y) {
    glPushMatrix();
        glTranslatef(x, y, 0);

        glColor3f(0.0f, 0.0f, 0.0f);
        lingkaran(0, 0, 18, 80);

        glColor3f(0.75f, 0.75f, 0.75f);
        lingkaran(0, 0, 9, 80);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
            glVertex2f(-12, 0);
            glVertex2f(12, 0);
            glVertex2f(0, -12);
            glVertex2f(0, 12);
        glEnd();

    glPopMatrix();
}

void mobil() {
    glPushMatrix();
        glTranslatef(0, 0, 0);

        // body mobil biru
        glColor3f(0.0f, 0.25f, 1.0f);
        kotak(-90, -80, 90, -35);

        // atap mobil
        glBegin(GL_POLYGON);
            glVertex2f(-55, -35);
            glVertex2f(-30, -5);
            glVertex2f(35, -5);
            glVertex2f(60, -35);
        glEnd();

        // jendela kiri
        glColor3f(0.75f, 0.92f, 1.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-47, -35);
            glVertex2f(-27, -12);
            glVertex2f(-5, -12);
            glVertex2f(-5, -35);
        glEnd();

        // jendela kanan
        glBegin(GL_POLYGON);
            glVertex2f(5, -35);
            glVertex2f(5, -12);
            glVertex2f(30, -12);
            glVertex2f(50, -35);
        glEnd();

        // lampu depan
        glColor3f(1.0f, 1.0f, 0.2f);
        kotak(82, -60, 90, -50);

        // lampu belakang
        glColor3f(1.0f, 0.0f, 0.0f);
        kotak(-90, -60, -82, -50);

        // roda
        roda(-55, -82);
        roda(55, -82);

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    background();
    mobil();

    glFlush();
}

void init() {
    glClearColor(0.55f, 0.82f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -200, 250);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Mobil Biru 2D");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
