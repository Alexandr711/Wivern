#pragma once

#include "Ui/AppMainWindow.hpp"

namespace Wivern {

class Application{

private:
    QString LanguageString;
    QString ThemeString;

    MainWindow* AppMainWindow;

public:
    Application();
    ~Application();

    void initApplication();
    void startMainWindowApplication();
};
}

