#ifndef STROKEINPUT_H
#define STROKEINPUT_H

#include <QtWidgets>
#include "alphabetlineedit.h"

class StrokeInput : public QWidget
{
    Q_OBJECT
public:
    explicit StrokeInput(QWidget *parent = nullptr);
    void setAlphabet(QString);
    QPushButton* setTapeString;
private:
    QLabel* title;
    AlphabetLineEdit* tapeStringInput;
signals:
    void onSetTapeString(QString);
};

#endif // STROKEINPUT_H
