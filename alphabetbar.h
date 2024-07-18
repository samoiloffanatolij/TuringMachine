#ifndef ALPHABETBAR_H
#define ALPHABETBAR_H

#include <QtWidgets>

class AlphabetBar : public QWidget
{
    Q_OBJECT
public:
    explicit AlphabetBar(QWidget *parent = nullptr);
    QPushButton* buildTableBtn;
    QPushButton* addState;
    QString getAlphabet();
private:
    QBoxLayout* hlayout;
    QLabel* alphabetLabel;
    QLineEdit* alphabetLineEdit;
signals:

};

#endif // ALPHABETBAR_H
