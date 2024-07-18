#ifndef STATETABLE_H
#define STATETABLE_H

#include <QtWidgets>


class StateTable : public QWidget
{
    Q_OBJECT
public:
    explicit StateTable(QWidget *parent = nullptr);
    void addStateRow();
    void removeStateRow();
    QPushButton* addState;
    QPushButton* removeState;
    QString getValue(QChar chr, int state);
    void setCurrentStateRow(int index);
    bool hasStopSymbol();
    QString alpha;
private:
    QTableWidget* tableWidget;
    QStringList headers;
    QBrush defaultBrush;
    void resetCells();
public slots:
    void buildTable(QString);
signals:

};

#endif // STATETABLE_H
