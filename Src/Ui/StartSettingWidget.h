#ifndef STARTSETTINGWIDGET_H
#define STARTSETTINGWIDGET_H

#include <QWidget>

namespace Ui {
class StartSettingWidget;
}

class StartSettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartSettingWidget(QWidget *parent = nullptr);
    ~StartSettingWidget();

private:
    Ui::StartSettingWidget *ui;
};

#endif // STARTSETTINGWIDGET_H
