#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qswitchbutton.h"
#include <QPushButton>
#include "mybutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QPushButton *pushButton = new QPushButton("button",this);

    //QSwitchButton *swithcbutton = new QSwitchButton(this);
    MyButton *mybutton = new MyButton(this);
   // swithcbutton->SetButtonStyle(QSwitchButton::Rectage);
    setCentralWidget(mybutton);
    //setc
    mybutton->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
