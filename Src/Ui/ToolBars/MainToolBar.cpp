#include "MainToolBar.hpp"

MainToolBar::MainToolBar(QWidget *parent): QToolBar(parent)
{
    OpenButton = new QToolButton;
    CreateButton = new QToolButton;
    SaveButton = new QToolButton;
    SaveAllButton = new QToolButton;
    UndoButton = new QToolButton;
    ReturnButton = new QToolButton;
}

MainToolBar::~MainToolBar()
{
    delete ReturnButton;
    delete UndoButton;
    delete SaveAllButton;
    delete SaveButton;
    delete CreateButton;
    delete OpenButton;
}

void MainToolBar::setWidgetsOnMainToolBar()
{
    addWidget(OpenButton);
    addWidget(CreateButton);
    addWidget(SaveButton);
    addWidget(SaveAllButton);
    addWidget(UndoButton);
    addWidget(ReturnButton);

}

void MainToolBar::setLanguage()
{
    OpenButton->setToolTip(OpenButtonToolTipName);
    CreateButton->setToolTip(CreateButtonToolTipName);
    SaveButton->setToolTip(SaveButtonToolTipName);
    SaveAllButton->setToolTip(SaveAllButtonToolTipName);
    UndoButton->setToolTip(UndoButtonToolTipName);
    ReturnButton->setToolTip(ReturnButtonToolTipName);
}

void MainToolBar::setColorTheme()
{
    setStyleSheet(StyleString);
}
