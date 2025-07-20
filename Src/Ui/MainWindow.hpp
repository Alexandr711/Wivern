#pragma once

#include <QMainWindow>

#include "MenuBar/FileMenu.h"


class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
};
