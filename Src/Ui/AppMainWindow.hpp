#pragma once


#include <QMainWindow>
#include <QMenuBar>
#include <QApplication>
#include <QMenu>
#include <QToolBar>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QToolButton>

#include <QDebug>


namespace Wivern {

class MainWindow: public QMainWindow{
    Q_OBJECT
private:
    //Config strings
    QString AppConfigLanguageString;
    QString AppConfigThemeString;

    //Menubar
    QMenuBar* MenuBar;

    //Menu "File"
    QMenu* MenuFile;

    //Menu "Open" in Menu "File"
    QMenu* MenuOpen;
    QAction* OpenFileAction;
    QAction* OpenProjectAction;

    //Menu "Create" in Menu "File"
    QMenu* MenuCreate;
    QAction* CreateFileAction;
    QAction* CreateProjectAction;

    //Exit Action
    QAction* ExitAction;


    //Menu Help
    QMenu* MenuHelp;

    //Select language Menu
    QMenu* MenuSelectLanguage;

    QMenu* RussiaLanguagesMenu;
    QAction* RussianAction;

    QMenu* WestEuropeLanguageMenu;
    QAction* EnglishAction;

    //Select theme Menu
    QMenu* MenuSelectTheme;
    QAction* DarkTheme;
    QAction* LightTheme;

    //Top toolbar
    QToolBar* TopToolBar;
    QToolButton* ToolBarOpenToolButton;
    QToolButton* ToolBarCreateToolButton;
    QToolButton* ToolBarSaveToolButton;
    QToolButton* ToolBarSaveAllToolButton;
    QToolButton* ToolBarUndoToolButton;
    QToolButton* ToolBarReturnToolButton;

private:
//create function
    void createMenuBar();
    void createMenuFile();
    void createMenuHelp();

    void allocateMemoryForTopToolBar();

//delete function
    void deleteMenuBar();
    void deleteMenuFile();
    void deleteMenuHelp();

    void deleteTopToolBar();

    QString openJsonFileForReading(QString);
    void openJsonFileForWriting(QString, QString, QString);

    QString openQssFile(QString);


public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void createWindow();
    void createTopToolBar();

    //Setting functions
    void setLanguage(QString);
    void setTheme(QString);

    //Connecting function
    void connectForMenuHelp();

public slots:
    void setRussianLanguageSlot();
    void setEnglishLanguageSlot();
    void setDarkThemeSlot();
    void setLightThemeSlot();
};

}
