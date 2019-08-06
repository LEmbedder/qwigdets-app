#ifndef FORMVIRTUALKEYBOARD_H
#define FORMVIRTUALKEYBOARD_H

#include <QWidget>

namespace Ui {
class FormVirtualKeyboard;
}

class FormVirtualKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit FormVirtualKeyboard(QWidget *parent = 0);
    ~FormVirtualKeyboard();

private:
    Ui::FormVirtualKeyboard *ui;
};

#endif // FORMVIRTUALKEYBOARD_H
