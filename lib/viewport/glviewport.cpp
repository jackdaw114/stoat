#include "viewport/glviewport.hpp"
#include "viewport/openglwindow.hpp"
#include <QPainter>
#include <QWindow>
#include <qglobal.h>
#include <qicon.h>
#include <qwidget.h>
#include <qwindow.h>

GLViewport::GLViewport(QWindow *parent) : OpenGLWindow(parent) {}

void GLViewport::initialize() {}

void GLViewport::render() {}

// ***************** testing ******************
//
/*
class TriangleWindow : public OpenGLWindow {
    public:
        using OpenGLWindow::OpenGLWindow;

        void initialize() override;
        void render() override;

    private:
        GLint m_matrixUniform = 0;
        QOpenGLBuffer m_vbo;
        QOpenGLShaderProgram *m_program = nullptr;
        int m_frame = 0;
};

MenuBar *MainWindow::menuBar() { return m_menuBar; }

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags) {
    QSurfaceFormat format;
    format.setSamples(16);
    setGeometry(50, 50, 300, 200);
    TriangleWindow *window = new TriangleWindow();
    QWidget *container = QWidget::createWindowContainer(window, this);
    window->setFormat(format);
    window->resize(640, 480);
    window->show();
    window->setAnimating(true);
    container->setMinimumSize(640, 480);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(container);

    show();
}
static const char *vertexShaderSource = "attribute highp vec4 posAttr;\n"
                                        "attribute lowp vec4 colAttr;\n"
                                        "varying lowp vec4 col;\n"
                                        "uniform highp mat4 matrix;\n"
                                        "void main() {\n"
                                        "   col = colAttr;\n"
                                        "   gl_Position = matrix * posAttr;\n"
                                        "}\n";

static const char *fragmentShaderSource = "varying lowp vec4 col;\n"
                                          "void main() {\n"
                                          "   gl_FragColor = col;\n"
                                          "}\n";
//! [3]

//! [4]
void TriangleWindow::initialize() {
    static const GLfloat vertices_colors[] = {+0.0f, +0.707f, 1.0f, 0.0f, 0.0f,
                                              -0.5f, -0.500f, 0.0f, 1.0f, 0.0f,
                                              +0.5f, -0.500f, 0.0f, 0.0f, 1.0f};

    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(vertices_colors, sizeof(vertices_colors));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                          nullptr);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                          reinterpret_cast<void *>(2 * sizeof(GLfloat)));

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                       vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                       fragmentShaderSource);
    m_program->bindAttributeLocation("posAttr", 0);
    m_program->bindAttributeLocation("colAttr", 1);
    m_program->link();
    m_program->bind();

    m_matrixUniform = m_program->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
}
//! [4]

//! [5]
void TriangleWindow::render() {
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);
    matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);

    m_program->setUniformValue(m_matrixUniform, matrix);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    m_program->release();

    ++m_frame;
}
*/
