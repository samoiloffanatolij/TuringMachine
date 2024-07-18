#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    toolBoxLayout = new QVBoxLayout;
    stateTable = new StateTable;
    inputTape = new InputTape;
    strokeInput = new StrokeInput;
    footerPanel = new FooterPanel;
    dialogAlphabet = new AlphabetInputWindow;
    warnForm = new WarningForm;

//    toolBoxLayout->addWidget(toolbox);
//    toolBoxLayout->addStretch(1);
    toolBoxLayout->addWidget(strokeInput);
    toolBoxLayout->addWidget(inputTape);
    toolBoxLayout->addStretch(1);
//    toolBoxLayout->addWidget(alphabetBar);
    toolBoxLayout->addWidget(stateTable, 4);
    toolBoxLayout->addWidget(footerPanel);

    connect(stateTable->removeState, SIGNAL(clicked(bool)), this, SLOT(removeTableStateSlot()));
    connect(stateTable->addState, SIGNAL(clicked(bool)), this, SLOT(addTableStateSlot()));
    connect(footerPanel->callAlphabetWindow, SIGNAL(clicked(bool)), this, SLOT(callAlphabetDialogWindow()));
    connect(dialogAlphabet, SIGNAL(OnConfirmWindow(QString,QString)), this, SLOT(onConfirmDialogWindow(QString,QString)));
    connect(strokeInput, SIGNAL(onSetTapeString(QString)), this, SLOT(setTapeString(QString)));
    connect(footerPanel->nextBtn, SIGNAL(clicked(bool)), this, SLOT(nextStep()));
    connect(footerPanel->playBtn, SIGNAL(clicked(bool)), this, SLOT(run()));
    connect(footerPanel->pauseBtn, SIGNAL(clicked(bool)), this, SLOT(pause()));
    connect(footerPanel->shutdownBtn, SIGNAL(clicked(bool)), this, SLOT(shutdown()));
    connect(footerPanel->increaseSpeed, SIGNAL(clicked(bool)), inputTape->crm, SLOT(increaseSpeed()));
    connect(footerPanel->decreaseSpeed, SIGNAL(clicked(bool)), inputTape->crm, SLOT(decreaseSpeed()));
    connect(inputTape->crm, SIGNAL(onFinished()), this, SLOT(onNextStepSlot()));
    connect(footerPanel->increaseSpeed, SIGNAL(clicked(bool)), this, SLOT(onSpeedIncreased()));
    connect(footerPanel->decreaseSpeed, SIGNAL(clicked(bool)), this, SLOT(onSpeedDecreased()));
    QWidget* centralWgt = new QWidget();
    centralWgt->setLayout(toolBoxLayout);
    this->setCentralWidget(centralWgt);

    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::removeTableStateSlot() {
    stateTable->removeStateRow();
}

void MainWindow::addTableStateSlot() {
    stateTable->addStateRow();
}

void MainWindow::callAlphabetDialogWindow() {
    dialogAlphabet->show();
}

void MainWindow::onConfirmDialogWindow(QString mainAlpha, QString addAlpha) {
    stateTable->buildTable(mainAlpha+"~"+addAlpha);
    strokeInput->setAlphabet(mainAlpha);
    dialogAlphabet->hide();
}

void MainWindow::setTapeString(QString tapeString) {
   inputTape->setTapeString(tapeString);
}

void MainWindow::onNextStepSlot() {
    if (!timerRunning) {
        this->footerPanel->nextBtn->setEnabled(true);
        qDebug() << "AA";
    }
}


void MainWindow::nextStep() /* 0 - single step, 1 - multy step*/{
    QString currentAction = stateTable->getValue(inputTape->getValue(carriageIndex), currentState);

    auto tokens = ActionParser::Parse(currentAction);
    int index = 0;
    if (tokens.size() == 0) {
        pause();
    }
    for (auto &c: tokens) {
        if (c[0] == 'Q' && c.size() > 1) {
            currentState = c.last(c.size() - 1).toInt();
            stateTable->setCurrentStateRow(currentState);
        } else if (c == "L" || c == "R") {
            this->footerPanel->nextBtn->setEnabled(false);
            if (carriageIndex + inputTape->movezone >= inputTape->getCellCount() && c == "R") {
                inputTape->move_left();
                carriageIndex--;
                inputTape->crm->translate(-25);
                qDebug() << "Q: "<<carriageIndex;
            } else if (carriageIndex == 0 && c == "L") {
                inputTape->move_right();
                carriageIndex++;
                inputTape->crm->translate(25);
            }
            inputTape->crm->moveX(c == "L" ? -25 : 25);
            carriageIndex += (c == "L" ? -1 : 1);
        } else if (c == "!"){
            pause();
        } else if (stateTable->alpha.contains(c[0])){
            inputTape->setValue(carriageIndex, c[0]);
//            if (index == tokens.size() - 1) {
//                pause();
//            }
        }
        index++;
    }
}

void MainWindow::run() {
    if (!stateTable->hasStopSymbol()) {
        warnForm->show();
        warnForm->showWarn("Не найден символ остановки.");
        return;
    }

    this->timerRunning = true;
    this->footerPanel->setEnabledBtns(false);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));
    timer->start(500);
}

void MainWindow::pause() {
    qDebug() << "paused";
    this->timerRunning = false;
    this->footerPanel->setEnabledBtns(true);
    if (timer->isActive()) {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));
        this->inputTape->crm->onPaused();
        //timer->stop();
    } /*else*/
//        timer->start(500);
}

void MainWindow::shutdown() {
    carriageIndex = 0;
    currentState = 0;
    stateTable->setCurrentStateRow(currentState);
    //timer->stop();
    timer = new QTimer(this);
    inputTape->reset();
}

void MainWindow::onSpeedIncreased() {
    ++carriageSpeed;
    if (carriageSpeed >= 10) carriageSpeed = 10;
    footerPanel->setSpeedValue(carriageSpeed);
}
void MainWindow::onSpeedDecreased() {
    --carriageSpeed;
    if (carriageSpeed <= 1) carriageSpeed = 1;
    footerPanel->setSpeedValue(carriageSpeed);
}
