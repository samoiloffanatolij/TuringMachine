#ifndef CARRIAGEMODEL_H
#define CARRIAGEMODEL_H

#include <QtWidgets>
#include <QPropertyAnimation>

class CarriageModel : public QWidget
{
    Q_OBJECT
public:
    explicit CarriageModel(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* e);
    void moveX(qreal x);
    bool isBusy();
    void reset();
    void translate(qreal x);
    void onPaused();
    int getSpeedValue();
public slots:
    void increaseSpeed();
    void decreaseSpeed();
private slots:
    void updatePixmap();

private:
    float speed = 0.5;
    QTimer* timer;
    QPainter* painter;
    qreal offset = 0;
    qreal targetPosX;
    QPoint* triangle;
    QQueue<qreal> queue;
    bool forwardMove;

signals:
    void onFinished();

};

#endif // CARRIAGEMODEL_H
