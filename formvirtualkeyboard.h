#ifndef FORMVIRTUALKEYBOARD_H
#define FORMVIRTUALKEYBOARD_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QtEvents>

namespace Ui {
class FormVirtualKeyboard;
}

class FormVirtualKeyboard : public QWidget
{
    Q_OBJECT
private:
    QGraphicsOpacityEffect *opacityEffect;
    bool mouse_is_press;     //鼠标是否按下
    QPoint  mouse_move_len;  //鼠标移动事件中，移动的距离
    QString lineEditText;
private:
    void setLineText(QString);
protected:
    virtual void mousePressEvent(QMouseEvent *event);    //鼠标点击事件
    virtual void mouseMoveEvent(QMouseEvent *event);     //鼠标移动事件
    virtual void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放事件

public:
    explicit FormVirtualKeyboard(QWidget *parent = 0);
    ~FormVirtualKeyboard();

private slots:
    void on_pushButton_19_clicked();


    void on_pushButton_0_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::FormVirtualKeyboard *ui;

    void sentText();
signals:
    void emitGetLineEditText(QString);

};

#endif // FORMVIRTUALKEYBOARD_H
