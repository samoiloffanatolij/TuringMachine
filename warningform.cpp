#include "warningform.h"

WarningForm::WarningForm(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout* hb = new QHBoxLayout(this);
    label = new QLabel;
    hb->addWidget(label);
    this->setLayout(hb);
    this->setMinimumWidth(200);

}

void WarningForm::showWarn(QString warning) {
    label->setText(warning);
}
