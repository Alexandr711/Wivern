#include "StartSettingWidget.h"
#include "ui_StartSettingWidget.h"

StartSettingWidget::StartSettingWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartSettingWidget)
{
    ui->setupUi(this);
    SettingDocument = nullptr;
    Status = true;

    KeyColorTheme = "Color Theme";
    KeyLanguage = "Language";

    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    setFixedSize(750, 400);
}

StartSettingWidget::~StartSettingWidget()
{
    delete ui;
    SettingDocument = nullptr;
}

void StartSettingWidget::createSettingFileSlot()
{
    int ColorThemeIndex = ui->ColorThemeComboBox->currentIndex();
    int LanguageIndex = ui->LanguageComboBox->currentIndex();

    setLanguageValue(LanguageIndex);
    setColorThemeValue(ColorThemeIndex);

    SettingDocument->openJsonFileForWriting(SettingFileName, KeyLanguage, ValueLanguage);
    SettingDocument->openJsonFileForWriting(SettingFileName, KeyColorTheme, ValueColorTheme);

    Status = false;
}

void StartSettingWidget::setLanguageValue(int IndexLanguage)
{
    switch(IndexLanguage){
    case 0: ValueLanguage = "English";
        break;
    case 1: ValueLanguage = "Russian";
        break;
        }
}

void StartSettingWidget::setColorThemeValue(int IndexColorTheme)
{
    switch(IndexColorTheme){
    case 0: ValueColorTheme = "Dark color theme";
        break;
    case 1: ValueColorTheme = "Light color theme";
        break;
    }
}

void StartSettingWidget::initApp()
{
    connect(ui->OkButton, SIGNAL(clicked(bool)), this, SLOT(createSettingFileSlot()));
    connect(ui->CancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void StartSettingWidget::setSettingDocument(Documents *Doc)
{
    SettingDocument = Doc;
}

