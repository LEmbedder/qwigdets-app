#include "mybutton2.h"

MyButton2::MyButton2(QWidget *parent) : QPushButton(parent)
{
    creatNewObject();
    init();
}
void MyButton2::creatNewObject(void)
{
    labelName = new QLabel(this);
    labelFunName1 = new QLabel(this);
    labelFunName2 = new QLabel(this);
}
void MyButton2::init()
{
    buttonWidth = 200;
    buttonHeight = 80;
    setFlat(true);//去掉边框

    isSelected = false;
    setMouseTracking(true);
    isEnable = true;

    /*button名字*/
    labelName->setText("频率步进模式");

    /*功能选择*/
    labelFunName1->setText("开启");
    labelFunName1->setFixedSize(buttonWidth/5,buttonHeight/3);
    labelFunName1->setAlignment(Qt::AlignCenter);
    labelFunName2->setText("关闭");
    labelFunName2->setFixedSize(buttonWidth/5,buttonHeight/3);
    labelFunName2->setAlignment(Qt::AlignCenter);
    select = true;

    isEnterEvent = false;

}

/*
 * 设置背景图片路径
*/
void MyButton2::setIcons(QString iconNormal, QString iconPress,QString iconHover)
{
    this->iconNormal.addFile(iconNormal);
    this->iconPress.addFile(iconPress);
    this->iconHover.addFile(iconHover);
    update();
}

void MyButton2::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    /*使用时图片*/
    if(isEnable)
    {
        if(isEnterEvent)
        {
            setIcon(iconHover);
        }
        else{
            setIcon(iconNormal);
        }
        if(select == true)
        {
            labelFunName1->setStyleSheet("background-color:lightgray");
            labelFunName2->setStyleSheet("background-color:transparent");

        }
        else//未选中状态
        {
            labelFunName2->setStyleSheet("background-color:lightgray");
            labelFunName1->setStyleSheet("background-color:transparent");
        }
    }
    else//不能使用时的颜色
    {

    }
    setIconSize(QSize(buttonWidth,buttonHeight));
    /*2button名字位置*/
    QFontMetrics fm(labelName->font());
    labelName->setGeometry((buttonWidth-fm.width(labelName->text()))/2
                           ,buttonHeight/6
                           ,labelName->width()+100
                           ,labelName->height());


}

void MyButton2::mousePressEvent(QMouseEvent *event)
{
    if(isEnable)
    {
        QPushButton::mousePressEvent(event);
        select = !select;

        emit clicked();
        emit clicked(select);//是否选中
    }
    else{

    }
    update();
}

void MyButton2::resizeEvent(QResizeEvent *event)
{
    labelFunName1->setGeometry(buttonWidth/6,buttonHeight*1/2,buttonWidth/8,buttonHeight/2-15);
    labelFunName2->setGeometry(buttonWidth*2/3,buttonHeight*1/2,buttonWidth/8,buttonHeight/2-15);
}
/*
 * 鼠标进入事件
*/
void MyButton2::enterEvent(QEvent *event)
{
    isEnterEvent = true;
    QPushButton::enterEvent(event);
    update();
}
/*
 * 鼠标出来事件
*/
void MyButton2::leaveEvent(QEvent *event)
{
    isEnterEvent = false;
    QPushButton::leaveEvent(event);
    update();
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
/*
 * 设置控件大小
*/
void MyButton2::setFixedSize(int w,int h)
{
    QPushButton::setFixedSize(w,h);
    buttonWidth = w;
    buttonHeight = h;
    update();
}
void MyButton2::setLabelNumbel(QString labelNumbel1,QString labelNumbel2)
{
    labelFunName1->setText(labelNumbel1);
    labelFunName2->setText(labelNumbel2);
    update();
}
