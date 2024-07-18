#ifndef INPUTTAPE_H
#define INPUTTAPE_H

#include <QtWidgets>
#include <QtCore>
#include "CharEdit.h"
#include "carriagemodel.h"

class InputTape : public QScrollArea
{
    Q_OBJECT
public:
    explicit InputTape(QWidget *parent = nullptr);
    void setTapeString(QString);
    CarriageModel* crm;
    QChar getValue(int);
    void setValue(int, QChar);
    void reset();
    void setCellCount(int);
    int getCellCount();
    void move_right();
    void move_left();
    const int movezone = 4;
private:
    QVector<QLineEdit*> charEdits;
    QHBoxLayout* layout;
    CharEdit* charEdit;
    int cellCount = 30;
    QString tapeString;
    QString defaultString;
    QWidget* scrollWgt;
    QVBoxLayout* vb;
    int moved = 0;
signals:

};

#endif // INPUTTAPE_H
