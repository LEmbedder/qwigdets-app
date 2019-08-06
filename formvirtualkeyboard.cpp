#include "formvirtualkeyboard.h"
#include "ui_formvirtualkeyboard.h"



FormVirtualKeyboard::FormVirtualKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVirtualKeyboard)
{

    this->setWindowFlags(Qt::FramelessWindowHint |
                         Qt::WindowSystemMenuHint |
                         Qt::WindowMinMaxButtonsHint);

    setWindowOpacity(0.7);

    ui->setupUi(this);
    setWindowTitle(tr("分辨率带宽RBW"));
    ui->lineEdit->setFixedHeight(40);
    ui->pushButton->setFixedHeight(50);
    ui->pushButton_2->setFixedHeight(50);
    ui->pushButton_3->setFixedHeight(50);
    ui->pushButton_4->setFixedHeight(50);
    ui->pushButton_5->setFixedHeight(50);
    ui->pushButton_6->setFixedHeight(50);
    ui->pushButton_7->setFixedHeight(50);
    ui->pushButton_7->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_8->setFixedHeight(50);
    ui->pushButton_9->setFixedHeight(50);
    ui->pushButton_10->setFixedHeight(50);
    ui->pushButton_11->setFixedHeight(50);
    ui->pushButton_12->setFixedHeight(50);
    ui->pushButton_13->setFixedHeight(50);
    ui->pushButton_14->setFixedHeight(50);
    ui->pushButton_15->setFixedHeight(50);
    ui->pushButton_16->setFixedHeight(50);
    ui->pushButton_17->setFixedHeight(50);
    ui->pushButton_18->setFixedHeight(50);
    ui->pushButton_19->setFixedHeight(50);
    show();
}

void FormVirtualKeyboard::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    mouse_is_press = true;
    mouse_move_len = event->globalPos() - this->pos();

}

void FormVirtualKeyboard::mouseMoveEvent(QMouseEvent *event)
{
    if (  mouse_is_press && (event->buttons() && Qt::LeftButton) &&
         (event->globalPos()-mouse_move_len).manhattanLength() > QApplication::startDragDistance()) //这句话其实就是：鼠标移动的距离大于最小可识别的距离
    {
        move(event->globalPos() - mouse_move_len);
        mouse_move_len = event->globalPos() - pos();
    }

}

void FormVirtualKeyboard::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_is_press = false;
}
FormVirtualKeyboard::~FormVirtualKeyboard()
{
    delete ui;
}

void FormVirtualKeyboard::on_pushButton_20_clicked()
{
    close();
}
