#include "inputtape.h"

InputTape::InputTape(QWidget *parent)
    : QScrollArea{parent}
{
    scrollWgt = new QWidget;
    QWidget* scrollCntWgt = new QWidget;
    layout = new QHBoxLayout;
    vb = new QVBoxLayout;
    crm = new CarriageModel();
    for (int i = 0; i < this->cellCount; ++i) {
        charEdits.append(new QLineEdit);
        charEdits[i]->setReadOnly(true);
        charEdits[i]->setMaximumSize(25, 30);
        layout->addWidget(charEdits[i]);
        if (i != 0) {
            setTabOrder(charEdits[i-1], charEdits[i]);
        }

    }

    QPushButton* qpsh = new QPushButton;
    scrollWgt->setLayout(layout);
    vb->addWidget(scrollWgt);
    vb->addWidget(crm);
    crm ->setMinimumWidth(cellCount * 25);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    scrollCntWgt->setLayout(vb);
//    this->setMaximumHeight(70);
    this->setWidget(scrollCntWgt);
    this->horizontalScrollBar()->setStyleSheet("QScrollBar {height:0px;}");
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void InputTape::setTapeString(QString s) {
    defaultString = s;
    tapeString = s;
    for (int i = 0; i < cellCount; ++i) {
        charEdits[i]->setText("");
    }
    for (int i = 0; i < fmin(s.size(), cellCount); ++i) {
        charEdits[i]->setText(QString(s[i]));
    }
}

QChar InputTape::getValue(int index) {
    if (charEdits[index]->text() == "") return '~';
    return charEdits[index]->text()[0];
}

void InputTape::setValue(int idx, QChar val) {
    int strIdx = moved + idx;
    if (strIdx >= 0 && strIdx < tapeString.size()) {
        tapeString[strIdx] = val;
    } else {
        QString paste = val;
        QString spaces = "";

        if (strIdx < 0) {
            for (int i = 0; i < abs(strIdx) - 1; ++i ) {
                spaces += " ";
            }
            tapeString = paste + spaces + tapeString;
            moved += paste.size() + spaces.size();
        } else {
            for (int i = 0; i < abs(strIdx) - tapeString.size(); ++i ) {
                spaces += " ";
            }
            tapeString += spaces + paste;
        }
    }
    qDebug() << "now: " << tapeString;
    charEdits[idx]->setText(QString(val));
}
void InputTape::reset() {
    crm->reset();
    setTapeString(defaultString);
}

void InputTape::setCellCount(int sz) {

    //scrollWgt->setMinimumWidth(30 * 25);
}

int InputTape::getCellCount() {
    return cellCount;
}

void InputTape::move_right() {
    qDebug() << "right: <" << tapeString << ">";
    moved--;
    for (int i = moved; i < cellCount + moved; ++i) {
        if (i >= 0 && i < tapeString.size())
            charEdits[i - moved]->setText(tapeString[i]);
        else charEdits[i - moved]->setText("");

    }
}

void InputTape::move_left() {
    qDebug() << "right: <" << tapeString << ">";
    moved++;
    for (int i = cellCount + moved - 1; i >= moved; --i) {
        if (i >= 0 && i < tapeString.size())
            charEdits[i - moved]->setText(tapeString[i]);
        else charEdits[i - moved]->setText("");
    }
}
