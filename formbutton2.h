#ifndef FORMBUTTON2_H
#define FORMBUTTON2_H

#include <QWidget>

namespace Ui {
class FormButton2;
}

class FormButton2 : public QWidget
{
    Q_OBJECT

public:
    explicit FormButton2(QWidget *parent = 0);
    ~FormButton2();

    void setButtonName(QString name);
    void setButtonFontColor(QColor color);
    void setButtonFontSize(int size);
    void setButtonLabe1And2(QString name1, QString name2);
private:
    Ui::FormButton2 *ui;

private:
    bool select;
    bool isEnterEvent;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);

};

#endif // FORMBUTTON2_H
