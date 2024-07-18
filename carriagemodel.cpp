#include "carriagemodel.h"

CarriageModel::CarriageModel(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(50, 50);

    triangle = new QPoint[3] {
        QPoint(13, 0),
        QPoint(0, 25),
        QPoint(25, 25),
    };

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePixmap()));
}
void CarriageModel::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    painter.translate(offset, 0);
    painter.setBrush(Qt::black);
    painter.drawPolygon(triangle, 3);
}

void CarriageModel::moveX(qreal x) {
    if (isBusy()) {
        //qDebug() << "queue";
        queue << x;
    } else {
        forwardMove = x > 0;
        targetPosX = offset + x;
        timer->start(10);
    }
}

void CarriageModel::updatePixmap() {
    if (forwardMove) {
        if (targetPosX <= offset) {
            if (targetPosX < offset) {
                translate(targetPosX - offset);
            }
            timer->stop();
            emit onFinished();
            if (!queue.isEmpty()) {
                moveX(queue.back());
                queue.pop_back();
            }
            //qDebug() << timer->isActive();
        } else {
            offset += speed;
            qDebug() << offset << " -> " << targetPosX;
            repaint();
        }
    } else {
        if (targetPosX >= offset) {
            timer->stop();
            emit onFinished();
            if (!queue.isEmpty()) {
                moveX(queue.back());
                queue.pop_back();
            }
            //qDebug() << timer->isActive();
        } else {
            offset -= speed;
            //qDebug() << offset << " " << targetPosX;
            repaint();
        }
    }


}

bool CarriageModel::isBusy() {
    return timer->isActive();
}

void CarriageModel::increaseSpeed() {
    qDebug() << "curr " << speed;
    speed += 0.1;
    qDebug() << "aft " << speed;
    if (speed > 1) {
        speed = 1;
    }
}
void CarriageModel::decreaseSpeed() {
    speed -= 0.1;
    if (speed <= 0.1) {
        speed = 0.1;
    }
}

void CarriageModel::reset() {
    offset = 0;
    repaint();
    queue.clear();
    timer->stop();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePixmap()));
}

void CarriageModel::translate(qreal x) {
    offset += x;
    repaint();
}

void CarriageModel::onPaused() {
    queue.clear();
}

int CarriageModel::getSpeedValue() {
    return speed * 10;
}

