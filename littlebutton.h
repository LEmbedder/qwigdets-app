#ifndef LITTLEBUTTON_H
#define LITTLEBUTTON_H

#include <QWidget>
#include <QLabel>

class LittleButton : public QWidget
{
    Q_OBJECT
private:
    QLabel name;

public:
    explicit LittleButton(QWidget *parent = 0);
protected:
};

#endif // LITTLEBUTTON_H
