#include "alphabetinputwindow.h"

AlphabetInputWindow::AlphabetInputWindow(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QVBoxLayout* vlayout = new QVBoxLayout;
    QHBoxLayout* labelsLayout = new QHBoxLayout;
    QHBoxLayout* inputsLayout = new QHBoxLayout;

    mainAlphabetLbl = new QLabel("Алфавит строки:");
    mainAlphabetInput = new QLineEdit;

    additionalAlphabetLbl = new QLabel("Алфавит доп. символов:");
    additionalAlphabetInput = new QLineEdit;

    connect(mainAlphabetInput, SIGNAL(textEdited(QString)), this, SLOT(onMainAlphaTyping(QString)));

    confirmBtn = new QPushButton("Задать алфавиты");
    connect(confirmBtn, &QPushButton::clicked, this, [this](){
        emit OnConfirmWindow(mainAlphabetInput->text(), additionalAlphabetInput->text());
    });

    labelsLayout->addWidget(mainAlphabetLbl);
    labelsLayout->addWidget(additionalAlphabetLbl);

    inputsLayout->addWidget(mainAlphabetInput);
    inputsLayout->addWidget(additionalAlphabetInput);

    vlayout->addLayout(labelsLayout);
    vlayout->addLayout(inputsLayout);

    layout->addLayout(vlayout);
    layout->addWidget(confirmBtn);
}

void AlphabetInputWindow::onMainAlphaTyping(QString new_value) {
    qDebug() << new_value;
}

void AlphabetInputWindow::onAdditionalAlphaTyping(QString new_value) {

}
