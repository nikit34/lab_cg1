#pragma once

#include <QPainter>
#include <cmath>
#include "panel.h"


class View: public QWidget {
public:
    View(QWidget *parent = 0);

    const Panel* controlPanel() const;
    void setControlPanel(const Panel* p);

protected:
    void paintEvent(QPaintEvent*);

private:
    const Panel* pan;
};
