#pragma concept

#include "Application.hpp"
#include <QDir>

Wivern::Application::Application()
{
    AppMainWindow = new MainWindow;
}

Wivern::Application::~Application()
{
    delete AppMainWindow;
}

void Wivern::Application::initApplication()
{
    QString ConfigAppString;

    QFile ConfigAppFile;

    ConfigAppFile.setFileName("AppConfig.json");
    ConfigAppFile.open(QIODevice::ReadOnly | QIODevice::Text);
    ConfigAppString = ConfigAppFile.readAll();
    ConfigAppFile.close();

    QJsonDocument JsonConfigAppDoc = QJsonDocument::fromJson(ConfigAppString.toUtf8());
    LanguageString = JsonConfigAppDoc["Language"].toString();
    ThemeString = JsonConfigAppDoc["Color theme"].toString();
}

void Wivern::Application::startMainWindowApplication()
{
    AppMainWindow->createWindow();
    AppMainWindow->setLanguage(LanguageString);
    AppMainWindow->setTheme(ThemeString);
    AppMainWindow->showMaximized();
    AppMainWindow->connectForMenuHelp();
}
