#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets> // Для корректной работы всех объектов окна (заместо <QTGui>)

class Widget : public QWidget
{
    Q_OBJECT
    // QTextCodec *codec;
    // Нужен для русификации строки (а именно постановки верной кодировки)
    // Для QT6 данный метод устарел (по умолчанию QT использует кодировку UTF-8)
    // Проверить на другой машине
    //      codec = QTextCodec::codecForName("UTF-8");
    //      setWindowTitle(codec->toUnicode("Возведение в квадрат")); и так далее
    // P.S. Возможно возвращение работы QTextCodec путем
    // Установки модуля QT5 Compability Module из установщика
    // А заместо QTextCodec можно будет воспользоваться QByteArray

    QFrame *frame;              // Рамка
    QLabel *inputLabel;         // Метка ввода
    QLineEdit *inputEdit;       // Строчный редактор ввода
    QLabel *outputLabel;        // Метка вывода
    QLineEdit *outputEdit;      // Строчный редактор вывода
    QPushButton *nextButton;    // кнопка Следующее
    QPushButton *exitButton;    // Кнопка Выход


public:
    Widget(QWidget *parent = nullptr);  //Конструктор

public slots:
    void begin();   // Метод начальной настройки интерфейса
    void calc();    // Метод реализации вычислений
};

// Методичка предлашает использовать Validator - однако по ходу программы от него нет никакого смысла
// Проверка строки на правильность ввода осуществляется методом calc

//class StrValidator:public QValidator // Класс компонента проверки ввода
//{
//public:
//    StrValidator(QObject *parent):QValidator(parent){}
//    virtual State validate(QString &str,int &pos)const
//    {
//        return Acceptable; // Метод всегда принимает вводимую строку
//    }
//};


#endif // WIDGET_H
