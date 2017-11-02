#include "QApplication"
#include "QGLWidget"
#include "QDebug"
#include "cmath"

# define M_PI2		3.14159265358979323846

class GLWidget : public QGLWidget{
    void initializeGL(){
        /// In modelview hand is at origin   
//        glClearColor(1.0, 0, 0, 1.0); ///< essential using white, as labels start from 0!!!!!         glEnable(GL_DEPTH_TEST);         glDisable(GL_LIGHTING);         glDisable(GL_DOUBLEBUFFER);         glEnableClientState(GL_VERTEX_ARRAY);                  /// Output opengl version         qDebug("OpenGL %d.%d",this->format().majorVersion(),this->format().minorVersion());
    }
    
    void paintGL(){
        glClearColor(0.0, 1, 0, 1.0); ///< essential using white, as labels start from 0!!!!!         glEnable(GL_DEPTH_TEST);         glDisable(GL_LIGHTING);         glDisable(GL_DOUBLEBUFFER);         glEnableClientState(GL_VERTEX_ARRAY);                  /// Output opengl version         qDebug("OpenGL %d.%d",this->format().majorVersion(),this->format().minorVersion());
        glMatrixMode(GL_MODELVIEW);         
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT);  

        glBegin(GL_POLYGON); 
            glVertex2f(-0.5, -1.5);
            glVertex2f(-0.5, 0.5);
            glVertex2f(0.5, 0.5); 
            glVertex2f(0.5, -0.5); 
        glEnd();
    }
};

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    GLWidget widget;
    widget.resize(640,480);
    widget.show();
    return app.exec();
}

