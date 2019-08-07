#include "formbutton.h"
#include "ui_formbutton.h"
#include <QIcon>
#include <QPainter>

#include <QPalette>
void FormButton::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if(isEnabled())
    {
        QPainter painter(this);
        if(isSelected)
        {
            painter.drawPixmap(rect(),QPixmap(":/image/2.png"),QRect());

        }
        else{
            if(isEnterEvent)
            {
                painter.drawPixmap(rect(),QPixmap(":/image/3.png"),QRect());
            }
            else
            {
                painter.drawPixmap(rect(),QPixmap(":/image/1.png"),QRect());
            }
        }
    }



}

void FormButton::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    isSelected = !isSelected;
    if(isSelected)
    {
        ui->lineEdit->selectAll();
    }
    else//未选中状态
    {
        ui->lineEdit->setCursorPosition(0);
    }
    emit clicked(isSelected);//是否选中
    update();
}

void FormButton::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
}

void FormButton::enterEvent(QEvent *event)
{
    QWidget::enterEvent(event);
    isEnterEvent = true;
    update();
}

void FormButton::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    isEnterEvent = false;
    update();
}

FormButton::FormButton(QWidget *parent) :
    QWidget(parent), ui(new Ui::FormButton)
{
    ui->setupUi(this);
    setFixedHeight(80);
    isSelected = false;
    isEnterEvent = false;
    ui->lineEdit->setText("100M");
    ui->lineEdit->setAlignment(Qt::AlignCenter);
    ui->lineEdit->setFixedHeight(30);

    /*父控件响应子控件事件*/
    ui->lineEdit->setAttribute(Qt::WA_TransparentForMouseEvents);
    show();
}

FormButton::~FormButton()
{
    delete ui;
}

/*
*/
void FormButton::setButtonName(QString name)
{
    ui->label->setText(name);
}
/*
 * 设置字体颜色
*/
void FormButton::setButtonFontColor(QColor color)
{
    QPalette p;
    p.setColor(QPalette::WindowText,color);
    ui->label->setPalette(p);
}
/*
 * @设置button名字字体大小
*/
void FormButton::setButtonFontSize(int size)
{
    QFont font;
    font.setPointSize(size);
    ui->label->setFont(font);
    update();
}
