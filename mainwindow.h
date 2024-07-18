#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtWidgets>
#include "statetable.h"
#include "inputtape.h"
#include "StrokeInput.h"
#include "alphabetinputwindow.h"
#include "footerpanel.h"
#include "actionparser.h"
#include "warningform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    StateTable* stateTable;
    InputTape* inputTape;
    StrokeInput* strokeInput;
    FooterPanel* footerPanel;
    AlphabetInputWindow* dialogAlphabet;
    WarningForm* warnForm;

private:
    Ui::MainWindow *ui;
    QVBoxLayout* toolBoxLayout;
    int carriageIndex = 0;
    int currentState = 0;
    QTimer* timer;
    bool timerRunning = false;
    int carriageSpeed = 5;

private slots:
    void removeTableStateSlot();
    void addTableStateSlot();
    void callAlphabetDialogWindow();
    void onConfirmDialogWindow(QString, QString);
    void setTapeString(QString);
    void nextStep();
    void run();
    void pause();
    void shutdown();
    void onNextStepSlot();
    void onSpeedIncreased();
    void onSpeedDecreased();
signals:
    void onNextStep();
};
#endif // MAINWINDOW_H
