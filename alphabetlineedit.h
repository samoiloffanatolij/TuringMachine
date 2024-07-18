#ifndef ALPHABETLINEEDIT_H
#define ALPHABETLINEEDIT_H

#include <QtWidgets>

class AlphabetLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit AlphabetLineEdit(QWidget *parent = nullptr);
    void setAlphabet(QString);
private:
    QString alphabet;
private slots:
    void onTextChanged();
signals:

};

#endif // ALPHABETLINEEDIT_H
