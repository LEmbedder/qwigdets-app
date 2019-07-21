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
    //ui->setupUi(this);
    QWidget *widget = new QWidget;
    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    MyButton *mybutton = new MyButton(widget);
    //mybutton->setDisabled(true);
    mybutton->setButtonFontSize(20);
    mybutton->setName("起始频率");
    mybutton->setButtonFontColor(QColor(Qt::red));

    QPushButton *b1 = new QPushButton("button");

    MyButton *mybutton2 = new MyButton(widget);
    mainlayout->addWidget(mybutton);
    mainlayout->addWidget(b1);
    mainlayout->addWidget(mybutton2);
    widget->setLayout(mainlayout);

//    QPushButton *b2 = new QPushButton("butt");
//    MyButton *b3 = new MyButton("bb",widget);
//    MyButton *b4 = new MyButton("dd",widget);
    //mainlayout->addWidget(b3);
    //mainlayout->addWidget(b2);

    widget->show();
    //setCentralWidget(mybutton);
    //show();


}

MainWindow::~MainWindow()
{
    delete ui;
}
