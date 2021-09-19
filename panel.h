#pragma once

#include <QWidget>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QVBoxLayout>


class QdoubleSpinBox;

class Panel : public QWidget{
    Q_OBJECT

public:
    Panel(QWidget* parent = 0);
    double aDo() const;
    double phDo() const;
    double step() const;

signals:
    void aChanged(double);
    void phChanged(double);
    void stepChanged(double);

private:
    QDoubleSpinBox* a;
    QDoubleSpinBox* ph;
    QDoubleSpinBox* st;
};
