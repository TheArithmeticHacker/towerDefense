#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPropertyAnimation>

class Worker : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Worker(QObject* parent = nullptr);

public slots:
    void startWorking(); 

signals:
    void workFinished(); 

private:
    QTimer* m_timer; 
    QPropertyAnimation* m_animation; 
};

#endif // WORKER_H
