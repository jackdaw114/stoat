#include "stapplication.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv) {
    StApplication app(argc, argv);
    QPushButton button("Hello world !");
    button.show();
    return app.exec();
}
