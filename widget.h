#ifndef widget_h
#define widget_h

#include "area.h"

class Widget: public QWidget {
protected:
    // QTextCodec * codec;
    Area * area;        // Область отображения рисунка
    QPushButton * btn;  // Кнопка

public:
    Widget();
};
#endif
