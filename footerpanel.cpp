#include "footerpanel.h"

FooterPanel::FooterPanel(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* topLayout = new QHBoxLayout;
    QHBoxLayout* bottomLayout = new QHBoxLayout;

    callAlphabetWindow = new QPushButton("Изменить алфавиты");
    speedValueLabel = new QLabel("5");
    speedLabel = new QLabel("Скорость:");
    increaseSpeed = new QPushButton("+");
    decreaseSpeed = new QPushButton("-");

    topLayout->addWidget(callAlphabetWindow);
    topLayout->addStretch(1);
    topLayout->addWidget(speedLabel);
    topLayout->addWidget(speedValueLabel);
    topLayout->addWidget(increaseSpeed);
    topLayout->addWidget(decreaseSpeed);

    playBtn = new QPushButton;
    nextBtn = new QPushButton;
    pauseBtn = new QPushButton;
    shutdownBtn = new QPushButton;

    QPixmap pixmapShutDown(":/Resources/shutdownbtn.png");
    QPixmap pixmapPause(":/Resources/pause.png");
    QPixmap pixmapPlay(":/Resources/play.png");
    QPixmap pixmapNextStep(":/Resources/nextstep.png");

    QIcon ButtonIconShutDown(pixmapShutDown);
    QIcon ButtonIconPause(pixmapPause);
    QIcon ButtonIconPlay(pixmapPlay);
    QIcon ButtonIconNextStep(pixmapNextStep);

    shutdownBtn->setIcon(ButtonIconShutDown);
    shutdownBtn->setIconSize(QSize(20, 20));

    pauseBtn->setIcon(ButtonIconPause);
    pauseBtn->setIconSize(QSize(20, 20));

    nextBtn->setIcon(ButtonIconNextStep);
    nextBtn->setIconSize(QSize(20, 20));

    playBtn->setIcon(ButtonIconPlay);
    playBtn->setIconSize(QSize(20, 20));


    bottomLayout->addWidget(playBtn);
    bottomLayout->addWidget(nextBtn);
    bottomLayout->addWidget(pauseBtn);
    bottomLayout->addWidget(shutdownBtn);

    layout->addLayout(topLayout);
    layout->addLayout(bottomLayout);




}

void FooterPanel::setEnabledBtns(bool enabled) {
    this->increaseSpeed->setEnabled(enabled);
    this->decreaseSpeed->setEnabled(enabled);
    this->nextBtn->setEnabled(enabled);
    this->shutdownBtn->setEnabled(enabled);
    this->playBtn->setEnabled(enabled);
    // this->pauseBtn->setEnabled(enabled);
}

void FooterPanel::setSpeedValue(int speedValue) {
    speedValueLabel->setText(QString::number(speedValue));
}
