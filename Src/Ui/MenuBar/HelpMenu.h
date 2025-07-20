#ifndef HELPMENU_H
#define HELPMENU_H

#include <QMenu>
#include <QAction>
#include <QString>

class HelpMenu : public QMenu
{
private:

    QMenu* SelectLanguageMenu;
    QAction* RussianLanguageAction;
    QAction* EnglishLanguageAction;

    QMenu* SelectColorThemeMenu;
    QAction* DarkColorAction;
    QAction* LightColorAction;

    QAction* AboutAction;


    QString SelectLanguageMenuName;

    QString SelectColorThemeMenuName;
    QString DarkColorActionName;
    QString LightColorActionName;

    QString AboutActionName;

    QString StyleString;

public:
    HelpMenu(QWidget *parent = nullptr);
    ~HelpMenu();

    void setSelectLanguageMenuName(QString);
    void setSelectColorThemeMenuName(QString);
    void setDarkColorActionName(QString);
    void setLightColorActionName(QString);
    void setAboutActionName(QString);

    void setStyleString(QString);

    void setItemOnMenuHelp();
    void setLanguage();
    void setColorTheme();
};

inline void HelpMenu::setSelectLanguageMenuName(QString _SelectLanguageMenuName)
{
    SelectLanguageMenuName = _SelectLanguageMenuName;
}

inline void HelpMenu::setSelectColorThemeMenuName(QString _SelectColorThemeMenuName)
{
    SelectColorThemeMenuName = _SelectColorThemeMenuName;
}

inline void HelpMenu::setDarkColorActionName(QString _DarkColorActionName)
{
    DarkColorActionName = _DarkColorActionName;
}

inline void HelpMenu::setLightColorActionName(QString _LightColorActionName)
{
    LightColorActionName = _LightColorActionName;
}

inline void HelpMenu::setAboutActionName(QString _AboutActionName)
{
    AboutActionName = _AboutActionName;
}

inline void HelpMenu::setStyleString(QString _StyleString)
{
    StyleString = _StyleString;
}

#endif // HELPMENU_H
