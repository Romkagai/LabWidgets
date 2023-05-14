#ifndef widget_h
#define widget_h
#include <QtGui>
class Counter : public QLineEdit
{
Q_OBJECT
public:
Counter(const QString & contents, QWidget *parent=0) : QLineEdit(contents,parent){}
signals:
void tick_signal();
public slots:
void add_one()
{
QString str=text();
int r=str.toInt();
if (r!=0 && r%5 ==0) emit tick_signal();
r++;
str.setNum(r);
setText(str);
}
};
class Widget: public QWidget
{
Q_OBJECT
protected:
QTextCodec *codec;
QLabel *label1,*label2;
Counter *edit1,*edit2;
QPushButton *calcbutton;
QPushButton *exitbutton;
public:
Widget(QWidget *parent = 0);
};
#endif

