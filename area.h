#ifndef area_h
#define area_h

#include "figura.h"

class Area: public QWidget {

  int myTimer;  // Идентификатор таймера
  float alpha;  // Угол поворота

public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;
    MyRect *myrect;
protected:
    //обработчики событий
    void paintEvent(QPaintEvent * event);
    void timerEvent(QTimerEvent * event);
    void showEvent(QShowEvent * event);
    void hideEvent(QHideEvent * event);
};

#endif