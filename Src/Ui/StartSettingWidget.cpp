#include "StartSettingWidget.h"
#include "ui_StartSettingWidget.h"

StartSettingWidget::StartSettingWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartSettingWidget)
{
    ui->setupUi(this);
}

StartSettingWidget::~StartSettingWidget()
{
    delete ui;
}
