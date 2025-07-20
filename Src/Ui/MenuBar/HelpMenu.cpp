#include "HelpMenu.h"

HelpMenu::HelpMenu(QWidget* parent): QMenu(parent)
{
    SelectLanguageMenu = new QMenu;
    RussianLanguageAction = new QAction;
    EnglishLanguageAction = new QAction;

    SelectColorThemeMenu = new QMenu;
    DarkColorAction = new QAction;
    LightColorAction = new QAction;

    AboutAction = new QAction;
}

HelpMenu::~HelpMenu()
{
    delete AboutAction;

    delete LightColorAction;
    delete DarkColorAction;
    delete SelectColorThemeMenu;

    delete EnglishLanguageAction;
    delete RussianLanguageAction;
    delete SelectLanguageMenu;
}

void HelpMenu::setItemOnMenuHelp()
{
    addMenu(SelectLanguageMenu);
    SelectLanguageMenu->addAction(EnglishLanguageAction);
    SelectLanguageMenu->addAction(RussianLanguageAction);

    addMenu(SelectColorThemeMenu);
    SelectColorThemeMenu->addAction(DarkColorAction);
    SelectColorThemeMenu->addAction(LightColorAction);

    addSeparator();
    addAction(AboutAction);
}

void HelpMenu::setLanguage()
{
    SelectLanguageMenu->setTitle(SelectLanguageMenuName);
    RussianLanguageAction->setText("Русский");
    EnglishLanguageAction->setText("English");

    SelectColorThemeMenu->setTitle(SelectColorThemeMenuName);
    DarkColorAction->setText(DarkColorActionName);
    LightColorAction->setText(LightColorActionName);

    AboutAction->setText(AboutActionName);
}

void HelpMenu::setColorTheme()
{
    setStyleSheet(StyleString);
}
