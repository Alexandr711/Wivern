#include "Application.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Application* Appl = new Application;
    Appl->initApplication();
    return app.exec();
}
