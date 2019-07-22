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
    QWidget *widget = new QWidget(this);
    QVBoxLayout *mainlayout = new QVBoxLayout(widget);
    MyButton *mybutton = new MyButton();
    //mybutton->setDisabled(true);
    mybutton->setButtonFontSize(15);
    mybutton->setName("起始频率");
    mybutton->setButtonFontColor(QColor(Qt::red));
    mybutton->setFixedSize(200,80);

    QPushButton *b1 = new QPushButton("button");

    MyButton *mybutton2 = new MyButton();
    mainlayout->addWidget(mybutton);
    mainlayout->addWidget(b1);
    mainlayout->addWidget(mybutton2);
    mybutton2->setFixedSize(200,80);


    setCentralWidget(widget);
    widget->show();
    show();


}

MainWindow::~MainWindow()
{
    delete ui;
}
