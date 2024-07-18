#ifndef WARNINGFORM_H
#define WARNINGFORM_H

#include <QtWidgets>

class WarningForm : public QWidget
{
    Q_OBJECT
public:
    explicit WarningForm(QWidget *parent = nullptr);
    void showWarn(QString);
private:
    QLabel* label;
signals:

};

#endif // WARNINGFORM_H
