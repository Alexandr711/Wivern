#include "Application.h"


Application::Application()
{
    Document = nullptr;
    StartSetting = nullptr;
    AppMainWindow = new MainWindow;
}

Application::~Application()
{
    delete AppMainWindow;
}

void Application::initApplication()
{
    Document = new Documents;
    QString SystemSettingsFile = "Setting.json";
    QFile File(SystemSettingsFile);
    bool StatusStartSetting = true;

    if(File.open(QIODevice::ReadOnly) == false)
    {
        StartSetting = new StartSettingWidget;
        StartSetting->setSettingDocument(Document);
        StartSetting->setSettingFileName(SystemSettingsFile);
        StartSetting->show();
        StartSetting->initApp();
        StatusStartSetting = StartSetting->getStatus();
        if(StatusStartSetting == false)
        {
            delete StartSetting;
            StartSetting = nullptr;
        }
    }
    if(File.isOpen() == true)
    {
        File.close();
    }


    QString Language;
    Language = Document->openJsonFileForReading(SystemSettingsFile);
    setLanguage(Language);

    if(StartSetting == nullptr)
        AppMainWindow->show();

    delete Document;
}

void Application::setLanguage(QString Language)
{
    Document = new Documents;
    if(Language == "Russian")
    {
        Document->openJsonFileForReading("Russian.json");
    }
    else if(Language == "Engilish")
    {
        Document->openJsonFileForReading("English.json");
    }
}
