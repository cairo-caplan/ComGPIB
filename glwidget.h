
#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>

class GLWidget : public QGLWidget {
    Q_OBJECT

public:
    GLWidget();
    ~GLWidget();
    void resizeGL(int width, int height);
    void paintGL();
    void initializeGL();
    float xmin,xmax,ymin,ymax,zmin,zmax;
    float *f1,*f2,*conv;
    float inc;
    int qtd_i;
    float cursor_x,cursor_y;


    //void keyPressEvent(QKeyEvent *event);
    //void changeEvent(QEvent *event);
    //void mousePressEvent(QMouseEvent *event);
    QMouseEvent *event;

protected:
private:
    //void mouseMoveEvent(QMouseEvent *event);
    QTimer *timer;
public slots:
    //void changeWidth(int w);
    void changeHeight(int h);

/*signals:
    EventChangeWidth(int w);
    EventChangeWidth(int h);
*/




};

#endif // GLWIDGET_H
