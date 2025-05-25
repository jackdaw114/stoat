#include "mainwindow.hpp"
#include "menubar/menubar.hpp"
#include "qnamespace.h"
#include "viewport/openglwindow.hpp"
#include <QOpenGLBuffer>
#include <QScreen>
#include <QToolBar>
#include <QVBoxLayout>
#include <qboxlayout.h>
#include <qmainwindow.h>
#include <qopenglshaderprogram.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qwindow.h>
#include <qwindowdefs.h>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags) {
    setMenuBar(new MenuBar());
}

void MainWindow::openProject(const QString &projectDir) {}
