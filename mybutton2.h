#ifndef MYBUTTON2_H
#define MYBUTTON2_H

#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QColor>
#include <QPainter>

class MyButton2 : public QPushButton
{
    Q_OBJECT
private:
    bool isEnable;                  //是否启用
    bool isSelected;                //当前是否为选中状态
    bool isAntiAliasing;            //是否开启抗锯齿
    QColor bordColorSelected;       //设置边框颜色
    QColor bordColorNotSelected;    //设置边框颜色
    int bord_size;                  //边框的线宽
    QColor backgroundColorSelected; //背景色
    QColor backgroundColorMoveOn;   //背景色
    QColor backgroundColorNotSelected;//未选择的button背景色
    QLabel *labelName;              //按键名字
    int buttonWidth;
    int buttonHeight;
    void init();

    void DrawBackRect(QPainter *painter, const QRectF &rect);
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);

public:
    explicit MyButton2(QWidget *parent = 0);

signals:

public slots:
};

#endif // MYBUTTON2_H
