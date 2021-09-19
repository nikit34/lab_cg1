#include "panel.h"


Panel::Panel(QWidget* parent): QWidget(parent){
    QLabel* lblA(new QLabel("A:"));
    a = new QDoubleSpinBox;
    a->setRange(1, 300);
    a->setSingleStep(0.1);
    a->setValue(150);

    QLabel* lblPh(new QLabel("Ph:"));
    ph = new QDoubleSpinBox;
    ph->setRange(0, 1);
    ph->setSingleStep(0.001);
    ph->setValue(0);

    QLabel* lblStep(new QLabel("Step:"));
    st = new QDoubleSpinBox;
    st->setRange(0.01, 1);
    st->setSingleStep(0.01);
    st->setValue(0.1);

    QVBoxLayout* lout(new QVBoxLayout);
    lout->addWidget(lblA);
    lout->addWidget(a);
    lout->addWidget(lblPh);
    lout->addWidget(ph);
    lout->addWidget(lblStep);
    lout->addWidget(st);
    lout->addStretch();

    setLayout(lout);

    connect(a, SIGNAL(valueChanged(double)),this,
            SIGNAL(aChanged(double)));
    connect(ph, SIGNAL(valueChanged(double)),this,
            SIGNAL(ph(double)));
    connect(st, SIGNAL(valueChanged(double)),this,
            SIGNAL(stepChanged(double)));
}

double Panel::aDo() const{
    return a->value();
}

double Panel::phDo() const{
    return ph->value();
}

double Panel::step() const{
    return st->value();
}
