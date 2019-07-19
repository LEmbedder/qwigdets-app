#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qswitchbutton.h"
#include <QPushButton>
#include "mybutton.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QWidget *widget = new QWidget;
    //QVBoxLayout *mainlayout = new QVBoxLayout(widget);

    //QPushButton *pushButton = new QPushButton("button",this);
    //QSwitchButton *swithcbutton = new QSwitchButton(this);
    MyButton *mybutton = new MyButton(this);
    //mybutton->setDisabled(true);
    mybutton->setButtonFontSize(15);
    mybutton->setName("起始频率");
    mybutton->setButtonFontColor(QColor(Qt::red));
    //mybutton->setDisabled(true);
    //mybutton->setDisabled(true);

//    QPushButton *b1 = new QPushButton("button");
//    QPushButton *b2 = new QPushButton("butt");
//    MyButton *b3 = new MyButton("bb",widget);
//    MyButton *b4 = new MyButton("dd",widget);
    //mainlayout->addWidget(b3);
    //mainlayout->addWidget(b2);

    setCentralWidget(mybutton);
    show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
