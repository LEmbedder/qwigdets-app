#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qswitchbutton.h"
#include <QPushButton>
#include "mybutton.h"

#include <QVBoxLayout>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QWidget *main_widget = new QWidget(this);
    //QVBoxLayout *mainlayout = new QVBoxLayout(main_widget);

    //QPushButton *pushButton = new QPushButton("button",this);
    //QSwitchButton *swithcbutton = new QSwitchButton(this);
    MyButton *mybutton = new MyButton(this);
    //mybutton->setDisabled(true);
//    MyButton *mybutton2 = new MyButton;

    //QPushButton *b1 = new QPushButton("button",this);
//    QPushButton *b2 = new QPushButton("butt");

    //swithcbutton->SetButtonStyle(QSwitchButton::Rectage);
    //setCentralWidget(mybutton);
    //mainlayout->addWidget(b1,0,0);
    //mainlayout->addWidget(b2,1,0);

//    centralWidget()->layout()->addWidget(mybutton);
//    centralWidget()->layout()->addWidget(mybutton2);
//    centralWidget()->layout()->setSpacing(0);
    setCentralWidget(mybutton);
    //mybutton->show();

    show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
