
/*
 * This code was created by Jeff Molofee 1999
 * And ported to C++/Qt4 by Wesley Stessens 2009
 *
 * Contact Jeff through his website: http://nehe.gamedev.net/
 * Contact Wesley for port-specific comments: wesley@ubuntu.com
 */

#include "glwidget.h"
#include <math.h>
#include <QKeyEvent>
#include <QTimer>
#include <QMouseEvent>
#include <QList>

#include <cstdio>

// Constructor
GLWidget::GLWidget() {
    GLWidget::xmin = -10.0f;
    GLWidget::xmax = 10.0f;
    GLWidget::ymin = -10.0f;
    GLWidget::ymax = 10.0f;
    GLWidget::zmin = -10.0f;
    GLWidget::zmax = 10.0f;
    setWindowTitle("Janela Grafica");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
}




// Empty destructor
GLWidget::~GLWidget() {}

// Initialize OpenGL
void GLWidget::initializeGL() {
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    qglClearColor(Qt::black); // Set the clear color to a black background

    glClearDepth(1.0f); // Depth buffer setup
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glDepthFunc(GL_LEQUAL); // Set type of depth test
    //glOrtho(-10.0, 10.0, -10.0,10.0 , -10.0, 10.0);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really nice perspective calculations
}

// This is called when the OpenGL window is resized
void GLWidget::resizeGL(int width, int height) {
    // Prevent divide by zero (in the gluPerspective call)
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height); // Reset current viewport

    glMatrixMode(GL_PROJECTION); // Select projection matrix
    glLoadIdentity(); // Reset projection matrix

    //gluPerspective(45.0f, static_cast<GLfloat>(width)/height, 0.1f, 100.0f); // Calculate aspect ratio
    printf(" da resizeGL xmin = %f, xmax= %f, ymin= %f, ymax = %f\n",xmin,xmax,ymin,ymax);
    //glOrtho(xmin, xmax, ymin,ymax , -1.0, 1.0);

    glOrtho(xmin, xmax, ymin,ymax , zmin, zmax);

    glMatrixMode(GL_MODELVIEW); // Select modelview matrix
    glLoadIdentity(); // Reset modelview matrix
}

// OpenGL painting code goes here
void GLWidget::paintGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xmin, xmax, ymin,ymax ,zmin,zmax);

    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer
    glLoadIdentity(); // Reset current modelview matrix

    //printf("da paintGL xmin = %f, xmax= %f, ymin= %f, ymax = %f\n",xmin,xmax,ymin,ymax);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(xmin,0.0,0.0);
        glVertex3f(xmax,0.0,0.0);
        glVertex3f(0.0,ymin,0.0);
        glVertex3f(0.0,ymax,0.0);
        glVertex3f(0.0,0.0,zmin);
        glVertex3f(0.0,0.0,zmax);
    glEnd();
/*
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
    float sizesegret_div_2 = (ymax-ymin)/40.0;
    for (float x = xmin;x<xmax;x+=1.0){
        glVertex3f(x,-sizesegret_div_2,0.0);
        glVertex3f(x,sizesegret_div_2,0.0);
    }

    sizesegret_div_2 = (xmax-xmin)/40.0;
    for (float y = ymin;y<ymax;y+=1.0){
        glVertex3f(-sizesegret_div_2,y,0.0);
        glVertex3f(sizesegret_div_2,y,0.0);
    }
    glEnd();


    sizesegret_div_2 = pow((ymax-ymin)*(ymax-ymin)\
            +(xmax-xmin)*(xmax-xmin),0.5)/160.0;


    //glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

*/
    //glRotatef(45.0,0.0,0.0,1.0);
    //glBegin(GL_LINES);
    //for (float z = zmin;z<zmax;z+=1.0){
    //    glVertex3f(-sizesegret_div_2,0.0,z);
    //    glVertex3f(sizesegret_div_2,0.0,z);
    //}
    //glEnd();
    //glPopMatrix();
    //glRotatef(-M_PI/4.0,0.0,0.0,1.0);
        /*glVertex3f(0.0,ymin,0.0);
        glVertex3f(0.0,ymax,0.0);
        glVertex3f(0.0,0.0,zmin);
        glVertex3f(0.0,0.0,zmax);*/


    glColor3f(1.0,0.0,0.0);

    float _x=xmin;
    glBegin(GL_LINE_STRIP);
    float g = 0;
        for (int i=0;i<=qtd_i-1;i++){
            glVertex3f(_x,f1[i],0.0);
            g = f1[i];
            //float lol = f1[i];
            //printf("i=%d , f1(%f)=%f",i,_x,f1[i]);
            //printf("%f\n",lol);
            _x+=inc;
        }
    glEnd();/*
   glColor3f(1.0,1.0,0.0);
    x=xmin;
    glBegin(GL_LINE_STRIP);
        for (i=0;i<=qtd_i-1;i++){
            glVertex3f(x,f2[i],0.0);
            x+=inc;
        }
    glEnd();
    glColor3f(0.0,0.0,1.0);
     x=xmin;
     glBegin(GL_LINE_STRIP);
         for (i=0;i<=qtd_i-1;i++){
             glVertex3f(x,conv[i],0.0);
             x+=inc;
         }
     glEnd();
     */


}
/*
// Key handler
void GLWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Escape:
        close(); // Quit on Escape
        break;
    case Qt::Key_F1:
        setWindowState(windowState() ^ Qt::WindowFullScreen); // Toggle fullscreen on F1
        break;
    case Qt::Key_Enter:
        printf("apertou enter\n");
        //timer->setSingleShot(true);
        break;
    default:
        QGLWidget::keyPressEvent(event); // Let base class handle the other keys
    }
}

void GLWidget::changeEvent(QEvent *event) {
    switch (event->type()) {
    case QEvent::WindowStateChange:
        // Hide cursor if the window is fullscreen, otherwise show it
        if (windowState() == Qt::WindowFullScreen)
            setCursor(Qt::BlankCursor);
        else
            unsetCursor();
        break;
    default:
        break;
    }
}
*/
//void GLWidget::timerfunc

void GLWidget::changeHeight(int h){
    //this->height() = h;
    this->resizeGL(this->height(),h);
}

