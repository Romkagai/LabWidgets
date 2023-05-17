#include "widget.h"

Widget::Widget(QWidget * parent): QWidget(parent) {
  //codec = QTextCodec::codecForName("Windows-1251");

try{
  this -> setWindowTitle("Счетчик");
  label1 = new QLabel("Cчет по 1", this);
  label2 = new QLabel("Cчет по 5", this);
  edit1 = new Counter("0", this);
  edit2 = new Counter("0", this);
  calcbutton = new QPushButton("+1", this);
  exitbutton = new QPushButton("Выход", this);
} catch (std::bad_alloc&) { qDebug() << "Memory error!"; exit(0);}

  QHBoxLayout * layout1 = new QHBoxLayout();
  QHBoxLayout * layout2 = new QHBoxLayout();
  QHBoxLayout * layout3 = new QHBoxLayout();
  QVBoxLayout * layout4 = new QVBoxLayout(this);

  layout1 -> addWidget(label1);
  layout1 -> addWidget(label2);

  layout2 -> addWidget(edit1);
  layout2 -> addWidget(edit2);

  layout3 -> addWidget(calcbutton);
  layout3 -> addWidget(exitbutton);

  layout4 -> addLayout(layout1);
  layout4 -> addLayout(layout2);
  layout4 -> addLayout(layout3);

  // Установка слотово-сигнальных соединений
  connect(calcbutton,   SIGNAL(clicked(bool)),  edit1,   SLOT(add_one()));
  connect(edit1,        SIGNAL(tick_signal()),  edit2,   SLOT(add_one()));
  connect(exitbutton,   SIGNAL(clicked(bool)),  this,    SLOT(close()));
}
