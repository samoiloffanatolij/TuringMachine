#include "alphabetbar.h"

AlphabetBar::AlphabetBar(QWidget *parent)
    : QWidget{parent}
{
    hlayout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    alphabetLabel = new QLabel("Current alphabet");
    alphabetLineEdit = new QLineEdit();
    buildTableBtn = new QPushButton("Build");
    addState = new QPushButton("Add state");

    hlayout->addWidget(alphabetLabel);
    hlayout->addWidget(alphabetLineEdit);
    hlayout->addWidget(buildTableBtn);
    hlayout->addWidget(addState);

    this->setLayout(hlayout);
}

QString AlphabetBar::getAlphabet() {
    return alphabetLineEdit->text();
}
