#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#include <QToolBar>
#include <QTabWidget>

#include "PlanToolsWidget.h"

namespace Wivern {

class MainToolBar : public QToolBar
{
public:
    QTabWidget* ToolTabWidget;

    PlanToolsWidget* PlanToolsWgt;

    QWidget* Detail3DToolsWgt;


    QWidget* Assembly3DToolsWgt;



public:
    MainToolBar(QWidget* parent = nullptr);
};
}


#endif // MAINTOOLBAR_H
