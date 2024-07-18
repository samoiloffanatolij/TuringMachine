#ifndef ALPHABETINPUTWINDOW_H
#define ALPHABETINPUTWINDOW_H

#include <QtWidgets>

class AlphabetInputWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AlphabetInputWindow(QWidget *parent = nullptr);

private:
    QLabel* mainAlphabetLbl;
    QLineEdit* mainAlphabetInput;
    QLabel* additionalAlphabetLbl;
    QLineEdit* additionalAlphabetInput;
    QPushButton* confirmBtn;
private slots:
    void onMainAlphaTyping(QString);
    void onAdditionalAlphaTyping(QString);
signals:
    void OnConfirmWindow(QString, QString);
};

#endif // ALPHABETINPUTWINDOW_H
