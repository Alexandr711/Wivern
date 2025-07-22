#ifndef APPLICATION_H
#define APPLICATION_H

#include "Src/Ui/MainWindow.hpp"
#include "Documents.h"
#include "Src/Ui/StartSettingWidget.h"

class Application
{
private:
    Documents* Document;
    StartSettingWidget* StartSetting;

public:
    Application();
    ~Application();

    void initApplication();
    void startMainWindow();
    void setLanguage(QString);
};



#endif // APPLICATION_H
