#include "mycombobox.h"

MyComboBox::MyComboBox(QWidget *parent) : QComboBox(parent)
{
    setStyleSheet(//"QComboBox{background-image:url(:/image/1.png);}"
                  "QComboBox::drop-down{background-color:transparent;"
                  //"image:url(image/4.png);"
                  "width:156px;heigth 142px;"
                  "}"
                  "QComboBox::down-arrow{"
                  "image:url(image/4.png);"
                  //"width:56px;heigth 42px;"
                  "}");

}
