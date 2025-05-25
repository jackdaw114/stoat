#include "stapplication.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv) {
    StApplication app(argc, argv);
    return app.exec();
}
