#include "strokeinput.h"

StrokeInput::StrokeInput(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    QWidget* inputWgt = new QWidget;
    QVBoxLayout* inputLayout = new QVBoxLayout;
    title = new QLabel("Строка на ленте:");
    tapeStringInput = new AlphabetLineEdit;
    setTapeString = new QPushButton("Задать строку");

    setTapeString->setMinimumHeight(40);

    inputLayout->addWidget(title);
    inputLayout->addWidget(tapeStringInput);
    inputWgt->setLayout(inputLayout);

    layout->addWidget(inputWgt);
    layout->addWidget(setTapeString);

    connect(setTapeString, &QPushButton::clicked, this, [this](){
        emit onSetTapeString(tapeStringInput->text());
    });
}

void StrokeInput::setAlphabet(QString alpha) {
    tapeStringInput->setAlphabet(alpha);
}
