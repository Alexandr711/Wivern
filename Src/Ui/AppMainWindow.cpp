#include "AppMainWindow.hpp"

//creating function
void Wivern::MainWindow::createMenuBar()
{
    MenuBar = new QMenuBar;
    MenuFile = new QMenu;
    MenuHelp = new QMenu;
}

void Wivern::MainWindow::createMenuFile()
{
    //Menu "Open"
    MenuOpen = new QMenu;
    OpenFileAction = new QAction;
    OpenProjectAction = new QAction;

    //Menu "Create"
    MenuCreate = new QMenu;
    CreateFileAction = new QAction;
    CreateProjectAction = new QAction;

    //Exit Action
    ExitAction = new QAction;
}

void Wivern::MainWindow::createMenuHelp()
{
    //Select language Menu
    MenuSelectLanguage = new QMenu;
    RussianAction = new QAction;
    EnglishAction = new QAction;

    //Select theme Menu
    MenuSelectTheme = new QMenu;
    DarkTheme = new QAction;
    LightTheme = new QAction;

    //Language region
    RussiaLanguagesMenu = new QMenu;
    WestEuropeLanguageMenu = new QMenu;

}

void Wivern::MainWindow::allocateMemoryForTopToolBar()
{
    TopToolBar = new QToolBar;
    ToolBarOpenButton = new QToolButton;
    ToolBarCreateAction = new QAction;
    ToolBarSaveAction = new QAction;
    ToolBarSaveAllAction = new QAction;
    ToolBarUndoAction = new QAction;
    ToolBarReturnAction = new QAction;
}


//delers
void Wivern::MainWindow::deleteMenuBar()
{
    delete MenuHelp;
    delete MenuFile;
    delete MenuBar;
}

void Wivern::MainWindow::deleteMenuFile()
{
    delete ExitAction;
    delete CreateProjectAction;
    delete CreateFileAction;
    delete MenuCreate;
    delete OpenProjectAction;
    delete OpenFileAction;
    delete MenuOpen;
}

void Wivern::MainWindow::deleteMenuHelp()
{
    delete WestEuropeLanguageMenu;
    delete RussiaLanguagesMenu;

    delete LightTheme;
    delete DarkTheme;
    delete MenuSelectTheme;

    delete EnglishAction;
    delete RussianAction;
    delete MenuSelectLanguage;
}

void Wivern::MainWindow::deleteTopToolBar()
{
    delete ToolBarReturnAction;
    delete ToolBarUndoAction;
    delete ToolBarSaveAllAction;
    delete ToolBarSaveAction;
    delete ToolBarCreateAction;
    delete ToolBarOpenButton;
    delete TopToolBar;
}



//Open files functions
QString Wivern::MainWindow::openJsonFileForReading(QString file)
{
    QString LanguageString;

    QFile JsonFile;

    JsonFile.setFileName(file);

    JsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    LanguageString = JsonFile.readAll();
    JsonFile.close();

    return LanguageString;
}

void Wivern::MainWindow::openJsonFileForWriting(QString file, QString key, QString value)
{
    QFile JsonFile;
    JsonFile.setFileName(file);
    JsonFile.open(QIODevice::ReadOnly| QIODevice::Text);
    QString TempString = JsonFile.readAll();
    JsonFile.close();


    QJsonDocument JsonDocument = QJsonDocument::fromJson(TempString.toUtf8());

    JsonFile.open(QIODevice::WriteOnly| QIODevice::Truncate |QIODevice::Text);

    QJsonObject JsonObject = JsonDocument.object();
    JsonObject.insert(key, value);
    QJsonDocument JsonDocumentTwo(JsonObject);
    TempString = JsonDocumentTwo.toJson(QJsonDocument::Indented);
    QTextStream stream(&JsonFile);
    stream << TempString;
    JsonFile.close();
}

QString Wivern::MainWindow::openQssFile(QString themeFile)
{
    QFile file(themeFile);
    file.open(QIODevice::ReadOnly);

    QString tempThemeString(file.readAll());
    return tempThemeString;
}


//Constructor and destructor
Wivern::MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    createMenuBar();
    createMenuFile();
    createMenuHelp();
    allocateMemoryForTopToolBar();
}

Wivern::MainWindow::~MainWindow()
{
    deleteTopToolBar();
    deleteMenuHelp();
    deleteMenuFile();
    deleteMenuBar();
}


//Create Main Window and Widgets for applications
void Wivern::MainWindow::createWindow()
{
    setMenuBar(MenuBar);
    //Add menu items for menu "File"
    MenuBar->addMenu(MenuFile);

    MenuFile->addMenu(MenuCreate);
    MenuCreate->addAction(CreateProjectAction);
    MenuCreate->addAction(CreateFileAction);

    MenuFile->addMenu(MenuOpen);
    MenuOpen->addAction(OpenProjectAction);
    MenuOpen->addAction(OpenFileAction);

    MenuFile->addSeparator();
    MenuFile->addAction(ExitAction);


    //Add menu item for menu "Help"
    MenuBar->addMenu(MenuHelp);

    MenuHelp->addMenu(MenuSelectLanguage);
    //Add menu for West European language
    MenuSelectLanguage->addMenu(WestEuropeLanguageMenu);
    WestEuropeLanguageMenu->addAction(EnglishAction);
    EnglishAction->setCheckable(true);
    //Add menu for Russian language
    MenuSelectLanguage->addMenu(RussiaLanguagesMenu);
    RussiaLanguagesMenu->addAction(RussianAction);
    RussianAction->setCheckable(true);

    MenuHelp->addMenu(MenuSelectTheme);
    MenuSelectTheme->addAction(DarkTheme);
    MenuSelectTheme->addAction(LightTheme);

    addToolBar(TopToolBar);

    createTopToolBar();
}

void Wivern::MainWindow::createTopToolBar()
{
    TopToolBar->addWidget(ToolBarOpenButton);
    TopToolBar->addAction(ToolBarCreateAction);
    TopToolBar->addAction(ToolBarSaveAction);
    TopToolBar->addAction(ToolBarSaveAllAction);
    TopToolBar->addAction(ToolBarUndoAction);
    TopToolBar->addAction(ToolBarReturnAction);
}

void Wivern::MainWindow::setLanguage(QString language)
{
    QString LanguageString;
    if(language == "Russian")
        LanguageString = openJsonFileForReading(":/Languages/Ru.json");
    else if(language == "English")
        LanguageString = openJsonFileForReading(":/Languages/En.json");

    QJsonDocument JsonLanguageDocument = QJsonDocument::fromJson(LanguageString.toUtf8());

    MenuFile->setTitle(JsonLanguageDocument["File"].toString());
    MenuCreate->setTitle(JsonLanguageDocument["Create"].toString());
    CreateProjectAction->setText(JsonLanguageDocument["Create project"].toString());
    CreateFileAction->setText(JsonLanguageDocument["Create file"].toString());
    MenuOpen->setTitle(JsonLanguageDocument["Open"].toString());
    OpenProjectAction->setText(JsonLanguageDocument["Open project"].toString());
    OpenFileAction->setText(JsonLanguageDocument["Open file"].toString());
    ExitAction->setText(JsonLanguageDocument["Exit"].toString());

    MenuHelp->setTitle(JsonLanguageDocument["Help"].toString());
    MenuSelectLanguage->setTitle(JsonLanguageDocument["Language"].toString());
    RussiaLanguagesMenu->setTitle(JsonLanguageDocument["Russia"].toString());
    RussianAction->setText(JsonLanguageDocument["Russian"].toString());
    WestEuropeLanguageMenu->setTitle(JsonLanguageDocument["West Europe"].toString());
    EnglishAction->setText(JsonLanguageDocument["English"].toString());
    MenuSelectTheme->setTitle(JsonLanguageDocument["Color theme"].toString());
    DarkTheme->setText(JsonLanguageDocument["Dark theme"].toString());
    LightTheme->setText(JsonLanguageDocument["Light theme"].toString());

    if(language == "Russian")
    {
        RussianAction->setChecked(true);
        EnglishAction->setChecked(false);
    }
    else if(language == "English")
    {
        RussianAction->setChecked(false);
        EnglishAction->setChecked(true);
    }
}

void Wivern::MainWindow::setTheme(QString theme)
{
    QString MainWindowStyleString;
    QString MenuStyleString;
    if(theme == "Dark theme"){
        MainWindowStyleString = openQssFile(":/DarkTheme/MainDarkColorTheme.qss");
        MenuStyleString = openQssFile(":/DarkTheme/MenuDarkColorTheme.qss");
    }

    setStyleSheet(MainWindowStyleString);

    MenuFile->setStyleSheet(MenuStyleString);
    MenuHelp->setStyleSheet(MenuStyleString);
    MenuOpen->setStyleSheet(MenuStyleString);
    MenuCreate->setStyleSheet(MenuStyleString);
    MenuSelectLanguage->setStyleSheet(MenuStyleString);
    MenuSelectTheme->setStyleSheet(MenuStyleString);
    RussiaLanguagesMenu->setStyleSheet(MenuStyleString);
    WestEuropeLanguageMenu->setStyleSheet(MenuStyleString);
    MenuOpen->setIcon(QIcon(":/IcoForMenu/DarkTheme/IcoForMenu/OpenIco.png"));
    //MenuOpen->
}


//Connecting function
void Wivern::MainWindow::connectForMenuHelp()
{
    connect(RussianAction, SIGNAL(triggered(bool)), this, SLOT(setRussianLanguageSlot()));
    connect(EnglishAction, SIGNAL(triggered(bool)), this, SLOT(setEnglishLanguageSlot()));
}


//Slots
void Wivern::MainWindow::setRussianLanguageSlot()
{
    setLanguage("Russian");
    openJsonFileForWriting("AppConfig.json", "Language", "Russian");
}

void Wivern::MainWindow::setEnglishLanguageSlot()
{
    setLanguage("English");
    openJsonFileForWriting("AppConfig.json", "Language", "English");
}



