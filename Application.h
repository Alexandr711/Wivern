#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include "Src/Ui/MainWindow.hpp"
#include "Src/Ui/Document.h"
#include "Src/Ui/StartSettingWidget.h"

class Application
{  
private:
    Documents* Document;
    StartSettingWidget* StartSetting;
    MainWindow* AppMainWindow;

public:
    Application();
    ~Application();

    void initApplication();
    void startMainWindow();
    void setLanguage(QString);
};



#endif // APPLICATION_H
