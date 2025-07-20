#ifndef FILEMENU_H
#define FILEMENU_H

#include <QMenu>
#include <QAction>
#include <QString>
#include <QVector>

class FileMenu: public QMenu
{
public:
    QMenu* CreateMenu;
    QAction* CreateFileAction;
    QAction* CreateProjectAction;

    QMenu* OpenMenu;
    QAction* OpenFileAction;
    QAction* OpenProjectAction;

    QAction* QuitAction;

    QString CreateMenuName;
    QString CreateFileActionName;
    QString CreateProjectActionName;
    QString OpenMenuName;
    QString OpenFileActionName;
    QString OpenProjectActionName;
    QString QuitActionName;

    QString StyleString;

public:
    FileMenu(QWidget *parent = nullptr);
    ~FileMenu();

    void setStyleString(QString);

    void setCreateMenuName(QString);
    void setCreteFileActionName(QString);
    void setCreateProjectActionName(QString);
    void setOpenMenuName(QString);
    void setOpenFileActionName(QString);
    void setOpenProjectActionName(QString);
    void setQuitActionName(QString);

    void setItemOnMenuBar();

    void setLanguage();
    void setColorTheme();
};

inline void FileMenu::setStyleString(QString _StyleString)
{
    StyleString = _StyleString;
}

inline void FileMenu::setCreateMenuName(QString _CreateMenuName)
{
    CreateMenuName = _CreateMenuName;
}

inline void FileMenu::setCreteFileActionName(QString _CreateFileActionName)
{
    CreateFileActionName = _CreateFileActionName;
}

inline void FileMenu::setCreateProjectActionName(QString _CreateProjectActionName)
{
    CreateProjectActionName = _CreateProjectActionName;
}

inline void FileMenu::setOpenMenuName(QString _OpenMenuName)
{
    OpenMenuName = _OpenMenuName;
}

inline void FileMenu::setOpenFileActionName(QString _OpenFileActionName)
{
    OpenFileActionName = _OpenFileActionName;
}

inline void FileMenu::setOpenProjectActionName(QString _OpenProjectActionName)
{
    OpenProjectActionName = _OpenProjectActionName;
}

inline void FileMenu::setQuitActionName(QString _QuitActionName)
{
    QuitActionName = _QuitActionName;
}

#endif // FILEMENU_H
