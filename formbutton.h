#ifndef FORMBUTTON_H
#define FORMBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class FormButton;
}

class FormButton : public QWidget
{
    Q_OBJECT
private:
    bool isSelected,isEnterEvent;
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
public:
    explicit FormButton(QWidget *parent = 0);
    ~FormButton();

    void setButtonFontSize(int size);
    void setButtonFontColor(QColor color);
    void setButtonName(QString name);
private:
    Ui::FormButton *ui;
signals:
    void clicked(bool);
};

#endif // FORMBUTTON_H
