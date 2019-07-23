#ifndef LITTLEBUTTON_H
#define LITTLEBUTTON_H

#include <QWidget>
#include <QLabel>

class LittleButton : public QWidget
{
public:
    QLabel name;
    LittleButton(QWidget *parent);
};

#endif // LITTLEBUTTON_H
