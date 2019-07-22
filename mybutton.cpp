#include "mybutton.h"

/*
 * @自定义两层的Button
 * @功能：
 *      点击，
 * @可以设置参数：
 *              buttonWidth，buttonHeight，backgroundColorSelected，bordColorSelected
 *              button_label，bord_size
*/
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    this->parent = parent;
    init();
}

MyButton::MyButton(QString name ,QWidget *parent):QPushButton(parent)
{
    this->parent = parent;
    init();
    labelName->setText(name);
}
void MyButton::init()
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
    labelName->setText("中心频率");

    /*输入框里的字*/
    line_input = new QLineEdit(this);
    line_input->setStyleSheet("background-color:lightgray");
    line_input->setAlignment(Qt::AlignCenter);
    line_input->setMaxLength(30);
    line_input->setText("10000M");
    /*父控件响应子控件事件*/
    line_input->setAttribute(Qt::WA_TransparentForMouseEvents);

    isOn = false;
}
void MyButton::paintEvent(QPaintEvent *event)
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
    else{
        bordColorNotSelected = QColor(Qt::gray);
        QPen pen(bordColorNotSelected,bord_size);//颜色，线宽
        painter.setPen(pen);

    }
    DrawBackRect(&painter, QRectF(0, 0, buttonWidth, buttonHeight));//画矩形
    /*2button名字*/
    QFontMetrics fm(labelName->font());
    labelName->setGeometry((buttonWidth-fm.width(labelName->text()))/2
                           ,buttonHeight/6
                           ,labelName->width()+100
                           ,labelName->height());

}
/*点击事件*/
void MyButton::mousePressEvent(QMouseEvent *event)
{
    if (isEnable)
    {
        QWidget::mousePressEvent(event);

        isSelected = !isSelected;
        if(isSelected)
        {
            backgroundColorSelected = QColor(Qt::darkGray);
            line_input->selectAll();
        }
        else//未选中状态
        {
            backgroundColorNotSelected = QColor(Qt::white);
            //line_input->selectedText();
        }

        emit clicked();
        emit clicked(isSelected);//是否选中
    }
    update();
}
/*
 * @鼠标移动事件
*/
void MyButton::mouseMoveEvent(QMouseEvent *event)
{
//    if(geometry().contains(mapFromGlobal(QCursor::pos())))
//    {
//        isOn = true;
//        backgroundColorMoveOn = QColor(Qt::green);
//    }
//    else
//    {
//        isOn = false;
//    }
    update();
    QWidget::mouseMoveEvent(event);
}
/*改变控件大小事件*/
void MyButton::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    line_input->setGeometry(5,buttonHeight*2/4,buttonWidth - 10,buttonHeight/2-15);
    update();
}

/*
 * 绘制矩形
*/
void MyButton::DrawBackRect(QPainter* painter, const QRectF& rect)
{
    if(isSelected)
    {
        painter->setBrush(QBrush(backgroundColorSelected));//设置画刷
    }
    else{
        if(isOn)
        {
            painter->setBrush(QBrush(backgroundColorMoveOn));//设置画刷
        }
        else
        {
            painter->setBrush(QBrush(backgroundColorNotSelected));//设置画刷
        }
    }
    painter->drawRoundRect(rect, 5, 5);

}
/*
 * 绘制输入框
*/
void MyButton::DrawInput(QPainter* painter, int button_widht, int button_heigth)
{
    QRectF rect(5,button_heigth*2/4,button_widht - 10,button_heigth/2-5);
    painter->setBrush(QBrush(QColor(Qt::lightGray)));//设置画刷
    painter->drawRoundRect(rect, 5, 5);

}
/*
 * @获取输入框的字符串
*/
QString MyButton::getButtonInput()
{
    return line_input->text();
}
/*
 * @设置button选中背景色
*/
void MyButton::setButtonBackgroundColorSelect(QColor color)
{
    backgroundColorSelected = color;
}
/*
 * @设置button未选中背景色
*/
void MyButton::setButtonBackgroundColorNotSelect(QColor color)
{
    backgroundColorNotSelected = color;
}
/*
 * @设置边框颜色和大小
*/
void MyButton::setButtonBordColorAndSize(QColor color , int size)
{
    bordColorSelected = color;
    bord_size = size;
}
/*
 * @设置button名字
*/
void MyButton::setName(QString name)
{
    labelName->setText(name);
}
/*
 * @设置控件不可用
*/
void MyButton::setDisabled(bool isDisable)
{
    isEnable = !isDisable;
    line_input->setDisabled(isDisable);
}
/*
 * @设置button名字字体大小
*/
void MyButton::setButtonFontSize(int size)
{
    QFont font;
    font.setPointSize(size);
    labelName->setFont(font);
    update();
}
/*
 * @设置button名字颜色
*/
void MyButton::setButtonFontColor(QColor color)
{    
    p.setColor(QPalette::WindowText,color);
    labelName->setPalette(p);
    repaint();
}
