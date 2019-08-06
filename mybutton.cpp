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
    creatNewObject();
    init();
}

MyButton::MyButton(QString name ,QWidget *parent):QPushButton(parent)
{
    creatNewObject();
    init();
    labelName->setText(name);
}
void MyButton::creatNewObject(void)
{
    labelName = new QLabel(this);
    line_input = new QLineEdit(this);
}
/*
 * 设置背景图片路径
*/
void MyButton::setIcons(QString iconNormal, QString iconPress,QString iconHover)
{
    this->iconNormal.addFile(iconNormal);
    this->iconPress.addFile(iconPress);
    this->iconHover.addFile(iconHover);
    update();
}
void MyButton::init()
{
    /*初始状态*/
    buttonWidth = 200;
    buttonHeight = 80;
    setStyleSheet("padding: -2px");
    setFlat(true);//去掉边框
    //setStyleSheet("QPushButton{outline:none;}");
    isSelected = false;
    //setMouseTracking(true);
    isEnable = true;
    isEnterEvent = false;

    /*button名字*/
    labelName->setText("中心频率");

    /*输入框里的字*/
    line_input->setStyleSheet("background-color:lightgray");
    line_input->setAlignment(Qt::AlignCenter);
    line_input->setMaxLength(30);
    line_input->setText("10000M");
    /*父控件响应子控件事件*/
    line_input->setAttribute(Qt::WA_TransparentForMouseEvents);
}

void MyButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    if(isEnable)
    {
        if(isSelected)
        {            
            setIcon(iconPress);

        }
        else{
            if(isEnterEvent)
            {
                setIcon(iconHover);
            }
            else
            {
                setIcon(iconNormal);
            }
        }

    }
    else//不能使用时的颜色
    {

    }

    setIconSize(QSize(buttonWidth,buttonHeight));
    /*2button名字位置*/
    QFontMetrics fm(labelName->font());
    labelName->setFixedSize(fm.size(Qt::TextSingleLine,labelName->text()));
    labelName->setGeometry((buttonWidth-fm.width(labelName->text()))/2
                           ,buttonHeight/6
                           ,fm.width(labelName->text())
                           ,fm.height());

}
/*点击事件*/
void MyButton::mousePressEvent(QMouseEvent *event)
{
    if (isEnable)
    {
        QPushButton::mousePressEvent(event);
        isSelected = !isSelected;
        //选中状态
        if(isSelected)
        {
            line_input->selectAll();
        }
        else//未选中状态
        {
            line_input->setCursorPosition(0);
        }
        emit clicked(isSelected);//是否选中
    }
    update();
}
/*
 * @鼠标移动事件
*/
void MyButton::mouseMoveEvent(QMouseEvent *event)
{
    QPushButton::mouseMoveEvent(event);
}
/*改变控件大小事件*/
void MyButton::resizeEvent(QResizeEvent *event)
{
    QPushButton::resizeEvent(event);
    line_input->setGeometry(5,buttonHeight*2/4,buttonWidth - 10,buttonHeight/2-15);
    update();
}
/*
 * 鼠标进入事件
*/
void MyButton::enterEvent(QEvent *event)
{
    isEnterEvent = true;
    QPushButton::enterEvent(event);
    update();
}
/*
 * 鼠标出来事件
*/
void MyButton::leaveEvent(QEvent *event)
{
    isEnterEvent = false;
    QPushButton::leaveEvent(event);
    update();
}


/*
 * @获取输入框的字符串
*/
QString MyButton::getButtonInput()
{
    return line_input->text();
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
void MyButton::setEnabled(bool enable)
{
    isEnable = enable;
    QPushButton::setEnabled(enable);
    line_input->setEnabled(enable);
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
    QPalette p;
    p.setColor(QPalette::ButtonText,color);
    labelName->setPalette(p);
}
void MyButton::setFixedSize(int w,int h)
{
    QPushButton::setFixedSize(w,h);
    buttonWidth = w;
    buttonHeight = h;
    update();
}
