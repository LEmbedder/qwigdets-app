#include "mybutton.h"

#include <QPainter>
#include <QRectF>


MyButton::MyButton(QWidget *parent)
    : QWidget(parent),buttonWidth(150), buttonHeight(80)
    ,backgroundColorSelected(Qt::white),bordColorSelected(Qt::blue)
    ,bord_size(3)
{
    resize(buttonWidth, buttonHeight);
    setMouseTracking(true);

}

void MyButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(isEnabled())
    {
        QPen pen(bordColorSelected,bord_size);//颜色，线宽
        painter.setPen(pen);
        painter.setBrush(QBrush(backgroundColorSelected));

        DrawBackRect(&painter, QRectF(0, 0, buttonWidth, buttonHeight));
    }
    return QWidget::paintEvent(event);
}
void MyButton::DrawBackRect(QPainter* painter, const QRectF& rect)
{
    painter->drawRoundRect(rect, 5, 5);

}
