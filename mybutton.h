#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QPushButton>

class MyButton : public QWidget
{
    Q_OBJECT

private:
    QWidget *parent;
    bool isEnable;      //是否启用
    bool isSelected;    //当前是否为选中状态
    bool isAntiAliasing;//是否开启抗锯齿

    QLineEdit *line_edit; //数据输入控件
    QVBoxLayout *main_layout;//主要布局
    QString button_label; //按键的功能标题

    QColor bordColorSelected;       //设置边框颜色
    int bord_size;                 //边框的线宽
    QColor backgroundColorSelected;//背景色
    QColor backgroundColorNotSelected;



    int buttonWidth;
    int buttonHeight;

    void DrawBackRect(QPainter *painter, const QRectF &rect);
    void DrawText(QPainter *painter, int x, int y, const QString string);
    void draw_input(QPainter *painter, int button_widht, int button_heigth);
    void init();
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);


public:
    explicit MyButton(QWidget *parent = 0);

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
