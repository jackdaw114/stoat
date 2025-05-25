#include "entt.hpp"
#include "mainwindow.hpp"
#include "stapplication.h"

StApplication::StApplication(int &argc, char **argv)
    : QApplication(argc, argv) {
    m_mainWindow = new MainWindow();
    m_mainWindow->show();
}

StApplication::~StApplication() {}
