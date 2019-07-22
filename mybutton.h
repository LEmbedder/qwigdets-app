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
class MyButton : public QPushButton
{
    Q_OBJECT

private:
    QWidget *parent;
    bool isEnable;      //是否启用
    bool isSelected;    //当前是否为选中状态
    bool isAntiAliasing;//是否开启抗锯齿
    QColor bordColorSelected;       //设置边框颜色
    QColor bordColorNotSelected;       //设置边框颜色
    int bord_size;                 //边框的线宽
    QColor backgroundColorSelected;//背景色
    QColor backgroundColorMoveOn;//背景色
    bool isOn;
    QColor backgroundColorNotSelected;//未选择的button背景色


    QLabel *labelName;
    QLineEdit *line_input;
    int buttonWidth;
    int buttonHeight;

    void DrawBackRect(QPainter *painter, const QRectF &rect);
    void DrawText(QPainter *painter, int x, int y, const QString string);
    void init();
    void DrawInput(QPainter *painter, int button_widht, int button_heigth);
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);


public:
    explicit MyButton(QWidget *parent = 0);
    MyButton(QString name, QWidget *parent = 0);
    QString getButtonInput(void);
    void setButtonBackgroundColorSelect(QColor color);
    void setButtonBackgroundColorNotSelect(QColor color);
    void setButtonBordColorAndSize(QColor color, int size);

    void setName(QString name);
    void setDisabled(bool isDisable);
    void setButtonFontSize(int size = 10);
    void setButtonFontColor(QColor color);
signals:
    /*
     * @brief       button点击信号
     * @param[in]   is_selected 当前是否选中
     */
    void clicked();
    void clicked(bool is_selected);
public slots:
};

#endif // MYBUTTON_H
