#include "mybutton.h"

#include <QPainter>
#include <QRectF>
#include <QHBoxLayout>
#include <QFontMetrics>
#include <QRect>


/*
 * @自定义两层的Button
 * @功能：
 *      点击，
 * @可以设置参数：
 *              buttonWidth，buttonHeight，backgroundColorSelected，bordColorSelected
 *              button_label，bord_size
*/
MyButton::MyButton(QWidget *parent) : QWidget(parent)
{
    this->parent = parent;
    init();
}
void MyButton::init()
{
    if(parent == NULL)
    {
        buttonWidth = 200;
        buttonHeight = 80;
    }
    else
    {
        buttonWidth = parent->width();
        buttonHeight = parent->height();
    }

    backgroundColorSelected = QColor(Qt::white);
    bordColorSelected = QColor(Qt::blue);
    button_label = "中心频率";
    bord_size = 3;
    isSelected = false;
    setMouseTracking(true);
    isEnable = true;
    isAntiAliasing = true;

}
void MyButton::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

    if (isAntiAliasing)
    {
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
    }

    if(isEnable)
    {
        /*1 画边框*/
        QPen pen(bordColorSelected,bord_size);//颜色，线宽
        painter.setPen(pen);
        DrawBackRect(&painter, QRectF(0, 0, buttonWidth, buttonHeight));//画矩形
        /*2 写字*/
        pen.setColor(QColor(Qt::black));//画笔颜色
        painter.setPen(pen);
        DrawText(&painter,buttonWidth,buttonHeight, button_label);

        /*3 画输入框*/
        draw_input(&painter, buttonWidth, buttonHeight);
    }
    else
    {

    }

    //return QPushButton::paintEvent(event);
}
/*点击事件*/
void MyButton::mousePressEvent(QMouseEvent *event)
{
    if (isEnable)
    {

        isSelected = !isSelected;
        if(isSelected)
        {
            backgroundColorSelected = QColor(Qt::darkGray);
        }
        else//未选中状态
        {
            backgroundColorSelected = QColor(Qt::white);
        }
        repaint();

        emit clicked();
        emit clicked(isSelected);//是否选中
    }

    return QWidget::mousePressEvent(event);
}
/*鼠标移动事件*/
void MyButton::mouseMoveEvent(QMouseEvent *event)
{

    //backgroundColorSelected = QColor(Qt::green);
    update();
    return QWidget::mouseMoveEvent(event);
}
/*改变控件大小事件*/
void MyButton::resizeEvent(QResizeEvent *event)
{
    buttonWidth = parent->width();
    buttonHeight = parent->height();
    update();
    QWidget::resizeEvent(event);
}

/*
 * 绘制字体
*/
void MyButton::DrawText(QPainter* painter,int x, int y, const QString string)
{
    QFont font;
    QFontMetrics fm(font);
    QRect rec = fm.boundingRect(button_label);
    painter->drawText((x-rec.width())/2,y/3,string);
}

/*
 * 绘制矩形
*/
void MyButton::DrawBackRect(QPainter* painter, const QRectF& rect)
{
    painter->setBrush(QBrush(backgroundColorSelected));//设置画刷
    painter->drawRoundRect(rect, 5, 5);

}
/*
 * 绘制输入框
*/
void MyButton::draw_input(QPainter* painter, int button_widht, int button_heigth)
{
    QRectF rect(5,button_heigth*2/4,button_widht - 10,button_heigth/2-5);
    painter->setBrush(QBrush(QColor(Qt::lightGray)));//设置画刷
    painter->drawRoundRect(rect, 5, 5);

}
