#include "FileMenu.h"

FileMenu::FileMenu(QWidget* parent): QMenu(parent)
{
    CreateMenu = new QMenu;
    CreateFileAction = new QAction;
    CreateProjectAction = new QAction;

    OpenMenu = new QMenu;
    OpenFileAction = new QAction;
    OpenProjectAction = new QAction;

    QuitAction = new QAction;
}

FileMenu::~FileMenu()
{
    delete QuitAction;

    delete OpenProjectAction;
    delete OpenFileAction;
    delete OpenMenu;

    delete CreateProjectAction;
    delete CreateFileAction;
    delete CreateMenu;
}

void FileMenu::setItemOnMenuBar()
{
    addMenu(CreateMenu);
    CreateMenu->addAction(CreateFileAction);
    CreateMenu->addAction(CreateProjectAction);

    addMenu(OpenMenu);
    OpenMenu->addAction(OpenFileAction);
    OpenMenu->addAction(OpenProjectAction);

    addSeparator();
    addAction(QuitAction);
}

void FileMenu::setLanguage()
{
    CreateMenu->setTitle(CreateMenuName);
    CreateFileAction->setText(CreateFileActionName);
    CreateProjectAction->setText(CreateProjectActionName);

    OpenMenu->setTitle(OpenMenuName);
    OpenFileAction->setText(OpenFileActionName);
    OpenProjectAction->setText(OpenProjectActionName);

    QuitAction->setText(QuitActionName);
}

void FileMenu::setColorTheme()
{
    setStyleSheet(StyleString);
}
