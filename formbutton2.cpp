#include "formbutton2.h"
#include "ui_formbutton2.h"
#include <QPainter>

FormButton2::FormButton2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormButton2)
{
    ui->setupUi(this);
    setFixedHeight(80);
    isEnterEvent = false;
    select = false;
}

FormButton2::~FormButton2()
{
    delete ui;
}

void FormButton2::paintEvent(QPaintEvent *event)
{

    QWidget::paintEvent(event);
    if(isEnabled())
    {
        QPainter painter(this);
        if(isEnterEvent)
        {
            painter.drawPixmap(rect(),QPixmap(":/image/3.png"),QRect());

        }
        else{
            painter.drawPixmap(rect(),QPixmap(":/image/1.png"),QRect());

        }
        if(select == true)
        {
            ui->label_3->setStyleSheet("background-color:transparent");
            ui->label_2->setStyleSheet("background-color:lightgray");

        }
        else//未选中状态
        {
            ui->label_3->setStyleSheet("background-color:lightgray");
            ui->label_2->setStyleSheet("background-color:transparent");
        }



    }

}

void FormButton2::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    select = !select;
}

void FormButton2::enterEvent(QEvent *event)
{
    QWidget::enterEvent(event);
    isEnterEvent = true;
    update();
}

void FormButton2::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    isEnterEvent = false;
    update();
}
/*
*/
void FormButton2::setButtonName(QString name)
{
    ui->label->setText(name);
}
/*
 * 设置字体颜色
*/
void FormButton2::setButtonFontColor(QColor color)
{
    QPalette p;
    p.setColor(QPalette::WindowText,color);
    ui->label->setPalette(p);
}
/*
 * @设置button名字字体大小
*/
void FormButton2::setButtonFontSize(int size)
{
    QFont font;
    font.setPointSize(size);
    ui->label->setFont(font);
    update();
}
void FormButton2::setButtonLabe1And2(QString name1,QString name2)
{
    ui->label_3->setText(name1);
    ui->label_2->setText(name2);
    update();
}
