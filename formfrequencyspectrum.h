#ifndef FORMFREQUENCYSPECTRUM_H
#define FORMFREQUENCYSPECTRUM_H

#include <QWidget>

namespace Ui {
class FormFrequencySpectrum;
}

class FormFrequencySpectrum : public QWidget
{
    Q_OBJECT

public:
    explicit FormFrequencySpectrum(QWidget *parent = 0);
    ~FormFrequencySpectrum();

private:
    Ui::FormFrequencySpectrum *ui;
};

#endif // FORMFREQUENCYSPECTRUM_H
