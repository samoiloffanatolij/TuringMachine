#include "toolbox.h"

ToolBox::ToolBox(QWidget *parent)
    : QWidget{parent}
{
    this->setPalette(QPalette(this->backgroundRole(), Qt::gray));
    this->resize(2000, 50);
    this->move(0, 0);
    this->setAutoFillBackground(true);

    buttonsLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    nextStep = new QPushButton(">");
    prevStep = new QPushButton("<");

    QPalette nextStepPal = nextStep->palette();
    nextStepPal.setColor(QPalette::Button, Qt::black);
    nextStepPal.setColor(QPalette::ButtonText, Qt::white);

    QPalette prevStepPal = nextStep->palette();
    prevStepPal.setColor(QPalette::Button, Qt::black);
    prevStepPal.setColor(QPalette::ButtonText, Qt::white);

    nextStep->setPalette(nextStepPal);
    nextStep->setAutoFillBackground(true);
    nextStep->setFlat(true);

    prevStep->setPalette(prevStepPal);
    prevStep->setAutoFillBackground(true);
    prevStep->setFlat(true);

    buttonsLayout->addWidget(prevStep);
    buttonsLayout->addWidget(nextStep);
    buttonsLayout->addStretch(1);

    this->setLayout(buttonsLayout);
}
