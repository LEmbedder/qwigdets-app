#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QLayout>

class MyButton : public QWidget
{
    Q_OBJECT

private:
    bool isEnable;      //是否启用
    bool isSelected;    //当前是否为选中状态
    bool isAntiAliasing;//是否开启抗锯齿

    QColor bordColorSelected;       //设置边框颜色
    int bord_size;                 //边框的线宽
    QColor backgroundColorSelected;//背景色
    QColor backgroundColorNotSelected;

    int buttonWidth;
    int buttonHeight;
    void DrawBackRect(QPainter *painter, const QRectF &rect);
protected:
    virtual void paintEvent(QPaintEvent* event);
public:
    explicit MyButton(QWidget *parent = 0);

signals:

public slots:
};

#endif // MYBUTTON_H
