#include "alphabetlineedit.h"

AlphabetLineEdit::AlphabetLineEdit(QWidget *parent)
    : QLineEdit{parent}
{
    connect(this, SIGNAL(textChanged(const QString&)), this, SLOT(onTextChanged()));
}

void AlphabetLineEdit::setAlphabet(QString alph) {
    this->alphabet = alph;
}

void AlphabetLineEdit::onTextChanged() {
    QString newContent = "";
    for (QChar c: text()) {
         if (alphabet.contains(c) || c == ' ') {
             newContent += c;
         }
    }
    qDebug(newContent.toStdString().c_str());
    setText(newContent);
}
