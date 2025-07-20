#pragma once

#include <QToolBar>
#include <QToolButton>

class MainToolBar: public QToolBar
{
private:
    QToolButton* OpenButton;
    QToolButton* CreateButton;
    QToolButton* SaveButton;
    QToolButton* SaveAllButton;
    QToolButton* UndoButton;
    QToolButton* ReturnButton;


    QString OpenButtonToolTipName;
    QString CreateButtonToolTipName;
    QString SaveButtonToolTipName;
    QString SaveAllButtonToolTipName;
    QString UndoButtonToolTipName;
    QString ReturnButtonToolTipName;

    QString StyleString;

public:
    MainToolBar(QWidget* parent);
    ~MainToolBar();

    void setWidgetsOnMainToolBar();
    void setLanguage();
    void setColorTheme();

    void setOpenButtonToolTipName(QString);
    void setCreateButtonToolTipName(QString);
    void setSaveButtonToolTipName(QString);
    void setSaveAllButtonToolTipName(QString);
    void setUndoButtonToolTipName(QString);
    void setReturnButtonToolTipName(QString);

    void setStyleString(QString);
};



inline void MainToolBar::setOpenButtonToolTipName(QString _OpenButtonToolTipName)
{
    OpenButtonToolTipName = _OpenButtonToolTipName;
}

inline void MainToolBar::setCreateButtonToolTipName(QString _CreateButtonToolTipName)
{
    CreateButtonToolTipName = _CreateButtonToolTipName;
}

inline void MainToolBar::setSaveButtonToolTipName(QString _SaveButtonToolTipName)
{
    SaveButtonToolTipName = _SaveButtonToolTipName;
}

inline void MainToolBar::setSaveAllButtonToolTipName(QString _SaveAllButtonToolTipName)
{
    SaveAllButtonToolTipName = _SaveAllButtonToolTipName;
}

inline void MainToolBar::setUndoButtonToolTipName(QString _UndoButtonToolTipName)
{
    UndoButtonToolTipName = _UndoButtonToolTipName;
}

inline void MainToolBar::setReturnButtonToolTipName(QString _ReturnButtonToolTipName)
{
    ReturnButtonToolTipName = _ReturnButtonToolTipName;
}

inline void MainToolBar::setStyleString(QString _StyleString)
{
    StyleString = _StyleString;
}
