#ifndef FORMVIRTUALKEYBOARD_H
#define FORMVIRTUALKEYBOARD_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QtEvents>

namespace Ui {
class FormVirtualKeyboard;
}

class FormVirtualKeyboard : public QWidget
{
    Q_OBJECT
private:
    QGraphicsOpacityEffect *opacityEffect;
    bool mouse_is_press;     //鼠标是否按下
    QPoint  mouse_move_len;  //鼠标移动事件中，移动的距离
protected:
    virtual void mousePressEvent(QMouseEvent *event);    //鼠标点击事件
    virtual void mouseMoveEvent(QMouseEvent *event);     //鼠标移动事件
    virtual void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放事件

public:
    explicit FormVirtualKeyboard(QWidget *parent = 0);
    ~FormVirtualKeyboard();

private slots:
    void on_pushButton_20_clicked();

private:
    Ui::FormVirtualKeyboard *ui;
};

#endif // FORMVIRTUALKEYBOARD_H
