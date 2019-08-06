#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qswitchbutton.h"
#include <QPushButton>
#include "mybutton.h"
#include "mybutton2.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialog>
#include <QComboBox>
#include <QIcon>
#include "mycombobox.h"

#include "formvirtualkeyboard.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *widget = new QWidget(this);
    QVBoxLayout *mainlayout = new QVBoxLayout(widget);

    MyButton *mybutton = new MyButton("起始频率");
    mybutton->setIcons(tr("image/1.png"),tr("image/2.png"),tr("image/3.png"));
    //mybutton->setEnabled(false);
    mybutton->setButtonFontSize(15);
    mybutton->setButtonFontColor(QColor(Qt::red));
    mybutton->setFixedSize(200,80);
    connect(mybutton,SIGNAL(clicked()),this,SLOT(ppp()));




    QPushButton *b1 = new QPushButton("button");

    MyButton2 *mybutton2 = new MyButton2();
    mybutton2->setIcons(tr("image/1.png"),tr("image/2.png"),tr("image/3.png"));
    mybutton2->setButtonFontSize(15);
    mybutton2->setFixedSize(200,80);

//    MyComboBox *box = new MyComboBox();
//    box->setFixedSize(200,40);
//    QFont font;
//    font.setPointSize(15);
//    box->setFont(font);
//    box->addItem("频率");
//    box->addItem("频谱");

    mainlayout->addWidget(mybutton);
    mainlayout->addWidget(b1);
    mainlayout->addWidget(mybutton2);
//    mainlayout->addWidget(box);
    FormVirtualKeyboard *key = new FormVirtualKeyboard();

    setCentralWidget(widget);
    widget->show();
    show();



}
void MainWindow::ppp()
{
    qDebug("hehe");
}
MainWindow::~MainWindow()
{
    delete ui;
}
