#include "worker.h"

Worker::Worker(QObject* parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Worker::startWorking);
    m_timer->start(2000); // Every 2 seconds, worker starts working
}

void Worker::startWorking()
{
    int repairAmount = 10;
    emit workFinished();
}
