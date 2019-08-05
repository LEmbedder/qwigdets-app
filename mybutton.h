#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QLineEdit>
#include <QPalette>
#include <QPainter>
#include <QFontMetrics>
#include <QRect>
#include <QPushButton>
#include <QIcon>

class MyButton : public QPushButton
{
    Q_OBJECT

private:
    bool isEnable;      //是否启用
    bool isSelected;    //当前是否为选中状态
    QIcon iconNormal,iconPress,iconHover;//
    bool isEnterEvent;
    QLabel *labelName;
    QLineEdit *line_input;
    int buttonWidth;
    int buttonHeight;

private:
    void init();
    void creatNewObject();
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);


public:
    explicit MyButton(QWidget *parent = 0);
    MyButton(QString name = 0,QWidget *parent = 0);
    QString getButtonInput(void);
    void setName(QString name);
    void setButtonFontSize(int size = 10);
    void setButtonFontColor(QColor color);
    void setIcons(QString iconNormal, QString iconPress, QString iconHover);
    void setEnabled(bool enable);
    void setFixedSize(int w, int h);
signals:
    /*
     * @brief       button点击信号
     * @param[in]   is_selected 当前是否选中
     */
    void clicked(bool isSelected);
public slots:
};

#endif // MYBUTTON_H
