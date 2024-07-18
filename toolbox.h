#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <QtWidgets>

class ToolBox : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBox(QWidget *parent = nullptr);
private:
    QPushButton* nextStep;
    QPushButton* prevStep;
    QPushButton* skipSteps;
    QBoxLayout* buttonsLayout;
signals:

};

#endif // TOOLBOX_H
