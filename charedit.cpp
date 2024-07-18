#include "charedit.h"

CharEdit::CharEdit(QWidget* parent) : QLineEdit(parent)
{
//    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setCursorWidth(0);

    connect(this, SIGNAL(textChanged(const QString&)), this, SLOT(onTextChanged()));
}

void CharEdit::onTextChanged() {
    if (text().length() > 1) {
        this->setText(text()[text().length()-1]);
    }

    qDebug(text().toStdString().c_str());
}

void CharEdit::focusInEvent(QFocusEvent* e) {
    QString styleSheetString = "border: 1px solid green;";
    this->setStyleSheet(styleSheetString);
}

void CharEdit::focusOutEvent(QFocusEvent* e) {
    QString styleSheetString = "border-color: inherit;";
    this->setStyleSheet(styleSheetString);
}

