#pragma once

#include <QHBoxLayout>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "view.h"


class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget() {};

private slots:
    void redrawOnValueChange(double);

private:
    View* view;
};
