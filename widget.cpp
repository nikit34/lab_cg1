#include "widget.h"


Widget::Widget(QWidget *parent): QWidget(parent){
    Panel* pan(new Panel);

    view = new View;
    view->setControlPanel(pan);

    QHBoxLayout* lout(new QHBoxLayout);
    lout->addWidget(view, 3);
    lout->addWidget(pan, 1);
    setLayout(lout);

    connect(pan, SIGNAL(aChanged(double)),
            this, SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(phChanged(double)),
            this, SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(stepChanged(double)),
            this, SLOT(redrawOnValueChange(double)));
}

void Widget::redrawOnValueChange(double){
    view->update();
}

