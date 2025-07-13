#include <QApplication>

#include "Ui/AppMainWindow.hpp"
#include "Application.hpp"

int main(int argc, char** argv){
    QApplication app(argc, argv);
    Wivern::Application a;
    a.initApplication();
    a.startMainWindowApplication();
    return app.exec();
}
