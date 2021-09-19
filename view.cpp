#include "view.h"


View::View(QWidget *parent): QWidget(parent), pan(0){
    QPalette pal(palette());
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);

    setAutoFillBackground(true);
}

void View::paintEvent(QPaintEvent*){
    if (!pan)
        return;

    const double a(pan->aDo());
    const double ph(pan->phDo());
    const double st(pan->step());

    const double pi(4 * atan(1));
    const double end(2 * pi + st);
    QPointF p1(a, 0);

    QPainter ptr(this);
    ptr.setPen(Qt::blue);

    const QPointF center(width() / 2.0, height() / 2.0);

    for (double t(st); t < end; t += st){
        QPointF p2(cos(7 * t) * cos(t), cos(7 * t) * sin(t));
        p2 *= 7 * a;

        ptr.drawLine(p1 + center, p2 + center);

        p1 = p2;
    }
}

const Panel* View::controlPanel() const{
    return pan;
}

void View::setControlPanel(const Panel* p){
    pan = p;
    update();
}
