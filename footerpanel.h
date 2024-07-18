#ifndef FOOTERPANEL_H
#define FOOTERPANEL_H

#include <QtWidgets>

class FooterPanel : public QWidget
{
    Q_OBJECT
public:
    explicit FooterPanel(QWidget *parent = nullptr);
    QPushButton* callAlphabetWindow;
    QPushButton* increaseSpeed;
    QPushButton* decreaseSpeed;
    QPushButton* playBtn;
    QPushButton* nextBtn;
    QPushButton* pauseBtn;
    QPushButton* shutdownBtn;
    void setEnabledBtns(bool);
    void setSpeedValue(int);
private:
    QLabel* speedLabel;
    QLabel* speedValueLabel;
signals:

};

#endif // FOOTERPANEL_H
