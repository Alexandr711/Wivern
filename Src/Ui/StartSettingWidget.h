#ifndef STARTSETTINGWIDGET_H
#define STARTSETTINGWIDGET_H

#include <QWidget>
#include <QString>
#include "Document.h"


namespace Ui {
class StartSettingWidget;
}

class StartSettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartSettingWidget(QWidget *parent = nullptr);
    ~StartSettingWidget();
    void setLanguageValue(int);
    void setColorThemeValue(int);
    void initApp();

    void setSettingFileName(QString);

    void setSettingDocument(Documents *Doc);

    bool getStatus();


private:
    Ui::StartSettingWidget *ui;
    Documents* SettingDocument;
    bool Status;

    QString SettingFileName;
    QString KeyColorTheme;
    QString KeyLanguage;

    QString ValueColorTheme;
    QString ValueLanguage;

public slots:
    void createSettingFileSlot();
};

inline void StartSettingWidget::setSettingFileName(QString Value)
{
    SettingFileName = Value;
}

inline bool StartSettingWidget::getStatus()
{
    return Status;
}

#endif // STARTSETTINGWIDGET_H
