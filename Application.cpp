#include "Application.h"


Application::Application()
{
    Document = nullptr;
    StartSetting = nullptr;
}

void Application::initApplication()
{
    Document = new Documents;
    QString SystemSettingsFile = "Setting.json";
    QFile File(SystemSettingsFile);
    if(File.open(QIODevice::ReadOnly) == false)
    {
        StartSetting = new StartSettingWidget;
        StartSetting->show();
        //Document->openJsonFileForWriting(SystemSettingsFile, "Language", "Russian");
        //Document->openJsonFileForWriting(SystemSettingsFile, "Color theme", "Dark");
    }
    if(File.isOpen() == true)
    {
        File.close();
    }

    QString Language;
    Language = Document->openJsonFileForReading(SystemSettingsFile);

    setLanguage(Language);

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
