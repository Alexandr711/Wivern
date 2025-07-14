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
    ToolBarOpenToolButton = new QToolButton;
    ToolBarCreateToolButton = new QToolButton;
    ToolBarSaveToolButton = new QToolButton;
    ToolBarSaveAllToolButton = new QToolButton;
    ToolBarUndoToolButton = new QToolButton;
    ToolBarReturnToolButton = new QToolButton;
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
    delete ToolBarReturnToolButton;
    delete ToolBarUndoToolButton;
    delete ToolBarSaveAllToolButton;
    delete ToolBarSaveToolButton;
    delete ToolBarCreateToolButton;
    delete ToolBarOpenToolButton;
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
    DarkTheme->setCheckable(true);
    MenuSelectTheme->addAction(LightTheme);
    LightTheme->setCheckable(true);

    addToolBar(TopToolBar);

    createTopToolBar();
}

void Wivern::MainWindow::createTopToolBar()
{
    TopToolBar->addWidget(ToolBarOpenToolButton);
    TopToolBar->addWidget(ToolBarCreateToolButton);
    TopToolBar->addWidget(ToolBarSaveToolButton);
    TopToolBar->addWidget(ToolBarSaveAllToolButton);
    TopToolBar->addWidget(ToolBarUndoToolButton);
    TopToolBar->addWidget(ToolBarReturnToolButton);
}


//Setting language
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

//Setting color theme
void Wivern::MainWindow::setTheme(QString theme)
{
    QString MainWindowStyleString;
    QString MenuStyleString;

    QString MenuIconsString;

    QString CreateButtonStyleStr;
    QString OpenButtonStyleStr;
    QString SaveButtonStyleStr;
    QString SaveAllButtonStyleStr;
    QString UndoButtonStyleStr;
    QString ReturnButtonStyleStr;

    if(theme == "Dark theme"){
        MainWindowStyleString = openQssFile(":/DarkTheme/MainDarkColorTheme.qss");
        MenuStyleString = openQssFile(":/DarkTheme/MenuDarkColorTheme.qss");
        MenuIconsString = openJsonFileForReading(":/DarkTheme/MenuFileIco.json");

        CreateButtonStyleStr = openQssFile(":/DarkTheme/DarkThemeForToolBars/CreateButton.qss");
        OpenButtonStyleStr = openQssFile(":/DarkTheme/DarkThemeForToolBars/OpenButton.qss");
        SaveButtonStyleStr = openQssFile(":/DarkTheme/DarkThemeForToolBars/SaveButton.qss");
        SaveAllButtonStyleStr = openQssFile(":/DarkTheme/DarkThemeForToolBars/SaveAllButton.qss");
        UndoButtonStyleStr = openQssFile(":/DarkTheme/DarkThemeForToolBars/UndoButton.qss");
        ReturnButtonStyleStr = openQssFile(":/DarkTheme/DarkThemeForToolBars/ReturnButton.qss");
    }
    else if(theme == "Light theme"){
        MainWindowStyleString = openQssFile(":/LightTheme/MainLightColorTheme.qss");
        MenuStyleString = openQssFile(":/LightTheme/MenuLightColorTheme.qss");
        MenuIconsString = openJsonFileForReading(":/LightTheme/MenuFileIco.json");

        CreateButtonStyleStr = openQssFile(":/LightTheme/LightThemeForTollBars/CreateButton.qss");
        OpenButtonStyleStr = openQssFile(":/LightTheme/LightThemeForTollBars/OpenButton.qss");
        SaveButtonStyleStr = openQssFile(":/LightTheme/LightThemeForTollBars/SaveButton.qss");
        SaveAllButtonStyleStr = openQssFile(":/LightTheme/LightThemeForTollBars/SaveAllButton.qss");
        UndoButtonStyleStr = openQssFile(":/LightTheme/LightThemeForTollBars/UndoButton.qss");
        ReturnButtonStyleStr = openQssFile(":/LightTheme/LightThemeForTollBars/ReturnButton.qss");

    }

    QJsonDocument JsonMenuIcoDocument = QJsonDocument::fromJson(MenuIconsString.toUtf8());

    setStyleSheet(MainWindowStyleString);

    MenuFile->setStyleSheet(MenuStyleString);
    MenuHelp->setStyleSheet(MenuStyleString);
    MenuOpen->setStyleSheet(MenuStyleString);
    MenuCreate->setStyleSheet(MenuStyleString);
    MenuSelectLanguage->setStyleSheet(MenuStyleString);
    MenuSelectTheme->setStyleSheet(MenuStyleString);
    RussiaLanguagesMenu->setStyleSheet(MenuStyleString);
    WestEuropeLanguageMenu->setStyleSheet(MenuStyleString);
    MenuOpen->setIcon(QIcon(JsonMenuIcoDocument["Open ico"].toString()));
    CreateProjectAction->setIcon(QIcon(JsonMenuIcoDocument["Create project ico"].toString()));
    CreateFileAction->setIcon(QIcon(JsonMenuIcoDocument["Create file ico"].toString()));
    OpenFileAction->setIcon(QIcon(JsonMenuIcoDocument["Open file ico"].toString()));
    OpenProjectAction->setIcon(QIcon(JsonMenuIcoDocument["Open project ico"].toString()));
    MenuSelectLanguage->setIcon(QIcon(JsonMenuIcoDocument["Language ico"].toString()));

    //Setting icons for TopToolBar
    JsonMenuIcoDocument = QJsonDocument::fromJson(CreateButtonStyleStr.toUtf8());

    ToolBarCreateToolButton->setStyleSheet(CreateButtonStyleStr);
    ToolBarOpenToolButton->setStyleSheet(OpenButtonStyleStr);
    ToolBarSaveToolButton->setStyleSheet(SaveButtonStyleStr);
    ToolBarSaveAllToolButton->setStyleSheet(SaveAllButtonStyleStr);
    ToolBarUndoToolButton->setStyleSheet(UndoButtonStyleStr);
    ToolBarReturnToolButton->setStyleSheet(ReturnButtonStyleStr);


    if(theme == "Dark theme")
    {
        DarkTheme->setChecked(true);
        LightTheme->setChecked(false);
    }
    else if(theme == "Light theme")
    {
        DarkTheme->setChecked(false);
        LightTheme->setChecked(true);
    }
}


//Connecting function
void Wivern::MainWindow::connectForMenuHelp()
{
    connect(RussianAction, SIGNAL(triggered(bool)), this, SLOT(setRussianLanguageSlot()));
    connect(EnglishAction, SIGNAL(triggered(bool)), this, SLOT(setEnglishLanguageSlot()));

    //connecting for change color theme
    connect(LightTheme, SIGNAL(triggered(bool)), this, SLOT(setLightThemeSlot()));
    connect(DarkTheme, SIGNAL(triggered(bool)), this, SLOT(setDarkThemeSlot()));
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

void Wivern::MainWindow::setDarkThemeSlot()
{
    setTheme("Dark theme");
    openJsonFileForWriting("AppConfig.json", "Color theme", "Dark theme");
}

void Wivern::MainWindow::setLightThemeSlot()
{
    setTheme("Light theme");
    openJsonFileForWriting("AppConfig.json", "Color theme", "Light theme");
}



