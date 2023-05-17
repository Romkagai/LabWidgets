#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget * parent): QWidget(parent) {
  //codec = QTextCodec::codecForName("Windows-1251");     // Использование кодировки не требуется
  setWindowTitle("Возведение в квадрат");               // Устанавливаем имя окна

try{
  frame = new QFrame(this);                             // Создали рамку с помощью new (добавили тень и панельную рамку вокруг)
  frame -> setFrameShadow(QFrame::Raised);              // Но наш класс - наследник QWidget
  frame -> setFrameShape(QFrame::Panel);                // QT сам вызовет необходимый деструктор, утечек памяти не будет

  inputLabel = new QLabel(("Введите число:"), this);    // Создаем поля текста - тут понятно
  inputEdit = new QLineEdit("", this);                  // Второе поле - поле ввода

  outputLabel = new QLabel(("Результат:"), this);       // Создаем объекты:     1) Поле текста: "Результат"
  outputEdit = new QLineEdit("", this);                 //                      2) Поле ввода, но в нем мы будем получать результат
  nextButton = new QPushButton(("Следующее"), this);    //                      3) Кнопка с текстом "Следующее"
  exitButton = new QPushButton(("Выход"), this);        //                      4) Кнопка с текстом "Выход"

    // Пример: Ловим bad_alloc
    //  const size_t size = 30000000000000000ul;
    //  char* ptr = NULL;
    //  ptr = new char[size];

} catch (std::bad_alloc&) { qDebug() << "Memory error"; exit(0); }

  QVBoxLayout * vLayout1 = new QVBoxLayout(frame);      // Создали вертикальный контейнер с рамкой, объявленной ранее (первая колонка объектов)
  QVBoxLayout * vLayout2 = new QVBoxLayout();           // Аналогично создали вертикальный контейнер
  QHBoxLayout * hLayout = new QHBoxLayout(this);        // Создали горизонтальный контейнер

  vLayout1 -> addWidget(inputLabel);                    // Добавили два поля текста и два поля с вводом
  vLayout1 -> addWidget(inputEdit);
  vLayout1 -> addWidget(outputLabel);
  vLayout1 -> addWidget(outputEdit);
  vLayout1 -> addStretch();                             // Добавили контейнеру свойство растяжения при растяжении окна
  vLayout2 -> addWidget(nextButton);                    // Положили кнопки Следующее и Выход
  vLayout2 -> addWidget(exitButton);
  vLayout2 -> addStretch();
  hLayout -> addWidget(frame);                          // Добавили рамку и вертикальный контейнер 2
  hLayout -> addLayout(vLayout2);

  begin();                                              // Вызываем функцию begin

  connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));  // Подключаем сигнально-слотовые соединения
  connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(begin()));  // На кнопки и окно ввода
  connect(inputEdit,  SIGNAL(returnPressed()),this, SLOT(calc()));
}

void Widget::begin() {
  inputEdit     -> clear();             // Очищаем поле ввода
  nextButton    -> setEnabled(false);   // Деактивируем кнопку Следующее
  nextButton    -> setDefault(false);   // Снимаем статус "по умолчанию" (кнопка нажимается при нажатии enter)
  inputEdit     -> setEnabled(true);    // Делаем активным (готовым к пользованию) окно ввода
  outputLabel   -> setVisible(false);   // Убираем из видимости поле Результат
  outputEdit    -> setVisible(false);   // Убираем из видимости поле ввода, в котором ожидаем увидеть результат
  outputEdit    -> setEnabled(false);   // Деактивируем поле ввода, в котором будет результат (пользователь не может менять содержимое)
  inputEdit     -> setFocus();          // Устанавливаем курсор на поле ввода (не нужно кликать мышью, сразу выберется)
}

void Widget::calc() {
  bool Ok = true;                       // Переменная для проверки преобразования
  float r, a;                           // Переменные для расчетов
  QString str = inputEdit -> text();    // Берем текст из поля ввода
  a = str.toDouble(&Ok);                // Конвертируем текст в число при этом, меняя значение Ok в случае неуспешной конвертации
  if (Ok) {
    r = a * a;                          // Возведение в квадрат
    str.setNum(r);                      // Конвертируем r в строку и отдаем в str
    outputEdit -> setText(str);         // Меняем интерфейс для дальнейшего пользования
    inputEdit -> setEnabled(false);
    outputLabel -> setVisible(true);
    outputEdit -> setVisible(true);
    nextButton -> setDefault(true);
    nextButton -> setEnabled(true);
    nextButton -> setFocus();
  } else
  if (!str.isEmpty()) {                                 // Не прошли проверку строки и при этом в ней что-то есть
    QMessageBox msgBox(QMessageBox::Information,        // Выводим окно с заголовком Возведение в квадрат.
      ("Возведение в квадрат."),                        // И текстом Введено неверное значение.
      ("Введено неверное значение."),
      QMessageBox::Ok);
    msgBox.exec();
  }
}
