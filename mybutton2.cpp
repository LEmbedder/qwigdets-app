#include "mybutton2.h"

MyButton2::MyButton2(QWidget *parent) : QPushButton(parent)
{
    init();
}

void MyButton2::init()
{
    buttonWidth = 200;
    buttonHeight = 80;
    backgroundColorNotSelected = QColor(Qt::white);
    backgroundColorSelected = QColor(Qt::darkGray);
    bordColorSelected = QColor(Qt::blue);
    bord_size = 3;
    isSelected = false;
    setMouseTracking(true);
    isEnable = true;
    isAntiAliasing = true;

    /*button名字*/
    labelName = new QLabel(this);
    labelName->setText("频率步进模式");

    /*功能选择*/
    labelFunName1 = new QLabel(this);
    labelFunName2 = new QLabel(this);
    labelFunName1->setText("开启");
    labelFunName2->setText("关闭");
    labelFunName1->setStyleSheet("background-color:lightgray");

    select = open;

}

void MyButton2::DrawBackRect(QPainter *painter, const QRectF &rect)
{
    if(isSelected)
    {
        painter->setBrush(QBrush(backgroundColorSelected));//设置画刷
    }
    else{
        painter->setBrush(QBrush(backgroundColorNotSelected));

    }
    painter->drawRoundRect(rect, 5, 5);
}

void MyButton2::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
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
    }
    else//不能使用时的颜色
    {
        bordColorNotSelected = QColor(Qt::gray);
        QPen pen(bordColorNotSelected,bord_size);//颜色，线宽
        painter.setPen(pen);

    }
    DrawBackRect(&painter, QRectF(0, 0, buttonWidth, buttonHeight));//画矩形
    /*2button名字位置*/
    QFontMetrics fm(labelName->font());
    labelName->setGeometry((buttonWidth-fm.width(labelName->text()))/2
                           ,buttonHeight/6
                           ,labelName->width()+100
                           ,labelName->height());
}

void MyButton2::mousePressEvent(QMouseEvent *event)
{
    if(select == open)
    {
        select = close;
        labelFunName1->setStyleSheet("background-color:white");
        labelFunName2->setStyleSheet("background-color:lightgray");
    }
    else//未选中状态
    {
        select = open;
        labelFunName1->setStyleSheet("background-color:lightgray");
        labelFunName2->setStyleSheet("background-color:white");

    }
    emit clicked();
    emit clicked(select);//是否选中
}

void MyButton2::resizeEvent(QResizeEvent *event)
{
    labelFunName1->setGeometry(buttonWidth/4,buttonHeight*1/2,buttonWidth/8,buttonHeight/2-15);
    labelFunName2->setGeometry(buttonWidth*2/3,buttonHeight*1/2,buttonWidth/8,buttonHeight/2-15);
}
/*
 * @设置button名字字体大小
*/
void MyButton2::setButtonFontSize(int size)
{
    QFont font;
    font.setPointSize(size);
    labelName->setFont(font);
    update();
}
