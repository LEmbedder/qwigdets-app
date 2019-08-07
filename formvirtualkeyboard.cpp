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
    ui->lineEdit->setText("");
    lineEditText = "";

    ui->lineEdit->setFixedHeight(40);
    ui->pushButton_0->setFixedHeight(50);
    ui->pushButton_1->setFixedHeight(50);
    ui->pushButton_2->setFixedHeight(50);
    ui->pushButton_3->setFixedHeight(50);
    ui->pushButton_4->setFixedHeight(50);
    ui->pushButton_5->setFixedHeight(50);
    ui->pushButton_6->setFixedHeight(50);
    ui->pushButton_7->setFixedHeight(50);
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

    ui->pushButton_0->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_1->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_4->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_5->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_6->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_7->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_8->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_9->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_10->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_11->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_12->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_13->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_14->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_15->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_16->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_17->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_18->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_19->setFocusPolicy(Qt::NoFocus);
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

void FormVirtualKeyboard::on_pushButton_19_clicked()
{
    close();
}
void FormVirtualKeyboard::setLineText(QString name)
{
    QString string = ui->lineEdit->text();
    string+=name;
    ui->lineEdit->setText(string);

}

void FormVirtualKeyboard::on_pushButton_0_clicked()
{
    setLineText("0");
}

void FormVirtualKeyboard::on_pushButton_16_clicked()
{
    QString string = ui->lineEdit->text();
    if(string.contains("."))
    {

    }
    else{

        setLineText(".");
    }
}

void FormVirtualKeyboard::on_pushButton_17_clicked()
{
    QString string = ui->lineEdit->text();
    QString tmp = "-";
    if(string.at(0) == "-")
    {
        string.remove("-");
        ui->lineEdit->setText(string);

    }
    else{
        tmp += string;
        ui->lineEdit->setText(tmp);

    }

}

void FormVirtualKeyboard::on_pushButton_1_clicked()
{
setLineText("1");
}

void FormVirtualKeyboard::on_pushButton_2_clicked()
{
setLineText("2");
}

void FormVirtualKeyboard::on_pushButton_3_clicked()
{
setLineText("3");
}

void FormVirtualKeyboard::on_pushButton_4_clicked()
{
setLineText("4");
}

void FormVirtualKeyboard::on_pushButton_5_clicked()
{
setLineText("5");
}

void FormVirtualKeyboard::on_pushButton_6_clicked()
{
setLineText("6");
}

void FormVirtualKeyboard::on_pushButton_7_clicked()
{
setLineText("7");
}

void FormVirtualKeyboard::on_pushButton_8_clicked()
{
setLineText("8");
}

void FormVirtualKeyboard::on_pushButton_9_clicked()
{
setLineText("9");
}

void FormVirtualKeyboard::sentText()
{
    lineEditText.clear();
    lineEditText = ui->lineEdit->text();
    ui->lineEdit->setText("");
    emitGetLineEditText(lineEditText);
}
void FormVirtualKeyboard::on_pushButton_13_clicked()
{
    setLineText("GHz");
    sentText();
    close();
}

void FormVirtualKeyboard::on_pushButton_14_clicked()
{
    setLineText("MHz");
    sentText();
    close();
}

void FormVirtualKeyboard::on_pushButton_15_clicked()
{
    setLineText("KHz");
    sentText();
    close();
}

void FormVirtualKeyboard::on_pushButton_18_clicked()
{
    setLineText("Hz");
    sentText();
    close();
}

void FormVirtualKeyboard::on_pushButton_12_clicked()
{
    lineEditText.clear();
    ui->lineEdit->setText(lineEditText);
}
