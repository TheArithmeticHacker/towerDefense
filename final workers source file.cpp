#include "worker.h"
#include <QPixmap>

Worker::Worker(QObject* parent) : QObject(parent)
{
    setPixmap(QPixmap(":/images/worker.png")); 

    
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Worker::startWorking);
    m_timer->start(2000); 

    
    m_animation = new QPropertyAnimation(this, "pos");
    m_animation->setDuration(5000);
    m_animation->setStartValue(QPointF(0, 0)); 
    m_animation->setEndValue(QPointF(450,280);
}

void Worker::startWorking()
{
    m_animation->start();
    connect(m_animation, &QPropertyAnimation::finished, this, &Worker::workFinished);
}
