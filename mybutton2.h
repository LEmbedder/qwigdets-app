#ifndef MYBUTTON2_H
#define MYBUTTON2_H

#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QColor>
#include <QPainter>
#include <QIcon>
class MyButton2 : public QPushButton
{
    Q_OBJECT
private:

    bool isEnable;                  //是否启用
    bool isSelected;                //当前是否为选中状态
    QLabel *labelName;              //按键名字
    QLabel *labelFunName1;
    QLabel *labelFunName2;
    int buttonWidth;
    int buttonHeight;
    bool select;
    bool isEnterEvent;
    QIcon iconNormal,iconPress,iconHover;//背景图片

private:
    void init();
    void creatNewObject();
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
public:
    explicit MyButton2(QWidget *parent = 0);

    void setButtonFontSize(int size);
    void setIcons(QString iconNormal = 0, QString iconPress = 0, QString iconHover = 0);
    void setFixedSize(int w, int h);
    void setLabelNumbel(QString labelNumbel1, QString labelNumbel2);
signals:

public slots:
};

#endif // MYBUTTON2_H
