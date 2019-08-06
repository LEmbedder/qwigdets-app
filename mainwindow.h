#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formvirtualkeyboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    FormVirtualKeyboard *key;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void ppp();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
