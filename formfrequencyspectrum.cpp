#include "formfrequencyspectrum.h"
#include "ui_formfrequencyspectrum.h"

FormFrequencySpectrum::FormFrequencySpectrum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFrequencySpectrum)
{
    ui->setupUi(this);
}

FormFrequencySpectrum::~FormFrequencySpectrum()
{
    delete ui;
}
