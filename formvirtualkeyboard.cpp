#include "formvirtualkeyboard.h"
#include "ui_formvirtualkeyboard.h"

FormVirtualKeyboard::FormVirtualKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVirtualKeyboard)
{
    ui->setupUi(this);
    setWindowTitle(tr("分辨率带宽RBW"));
    show();
}

FormVirtualKeyboard::~FormVirtualKeyboard()
{
    delete ui;
}
