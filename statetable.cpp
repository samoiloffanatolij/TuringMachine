#include "statetable.h"

StateTable::StateTable(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* btnLayout = new QHBoxLayout;

    tableWidget = new QTableWidget;
    addState = new QPushButton("+");
    removeState = new QPushButton("-");

    btnLayout->addWidget(addState);
    btnLayout->addWidget(removeState);

    addState->setMaximumWidth(30);
    removeState->setMaximumWidth(30);

    layout->addWidget(tableWidget);
    layout->addLayout(btnLayout);
    btnLayout->addStretch(1);
    this->setLayout(layout);
}

void StateTable::buildTable(QString s) {
    bool easyMode = 1;
    if (alpha.size()) {
        for (auto& header: alpha) {
            easyMode &= s.contains(header);
            qDebug() << header << " in " << s;
        }
    }



    tableWidget->setColumnCount(s.length());
    alpha = s;
    if (!tableWidget->rowCount()) {
        addStateRow();
        defaultBrush = tableWidget->item(0, 0)->background();
        setCurrentStateRow(0);
    }
    QStringList headersH;
    for (auto i: s) {
        headersH << i;
    }
    tableWidget->setHorizontalHeaderLabels(headersH);
    if (!easyMode) resetCells();
}

void StateTable::addStateRow() {
    qDebug() << "AAAA";
    headers << "Q" + QString::number(tableWidget->rowCount());
    tableWidget->setRowCount(tableWidget->rowCount() + 1);
    tableWidget->setVerticalHeaderLabels(headers);
    for (int i = 0; i < tableWidget->columnCount(); ++i) {
        tableWidget->setItem(tableWidget->rowCount() - 1, i, new QTableWidgetItem());
    }
}

void StateTable::removeStateRow() {
    if (headers.size()) {
        headers.pop_back();
        tableWidget->setRowCount(tableWidget->rowCount() - 1);
    }
    tableWidget->setVerticalHeaderLabels(headers);
}

QString StateTable::getValue(QChar chr, int state) {
    qDebug() << "C";
    qDebug() << alpha.indexOf(chr) << " -> " << chr << " " << state;

    for (int i = 0; i < tableWidget->rowCount(); ++i) {
        for (int j = 0; j < tableWidget->columnCount(); ++j) {
            qDebug() << i << " " << j;
            qDebug() << (tableWidget->item(i, j)->text());
        }
    }
    qDebug() << "D";
    if (chr == ' ') chr = '~';
    auto item = tableWidget->item(state, alpha.indexOf(chr))->text();
    qDebug() << "E";
    return item;

}

void StateTable::setCurrentStateRow(int index) {
    for (int i = 0; i < tableWidget->rowCount(); ++i) {
        for (int j = 0; j < tableWidget->columnCount(); ++j) {
            if (i == index)
                tableWidget->item(i, j)->setBackground(Qt::gray);
            else
                tableWidget->item(i, j)->setBackground(defaultBrush);
        }
    }
}

bool StateTable::hasStopSymbol() {
    for (int i = 0; i < tableWidget->rowCount(); ++i) {
        for (int j = 0; j < tableWidget->columnCount(); ++j) {
            if (tableWidget->item(i, j)->text().contains("!"))
                return true;
        }
    }
    return false;
}

void StateTable::resetCells() {
    for (int i = 0; i < tableWidget->rowCount(); ++i) {
        for (int j = 0; j < tableWidget->columnCount(); ++j) {
            if (tableWidget->item(i, j))
                tableWidget->item(i, j)->setText("");
        }
    }
}
