#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>

class Worker : public QObject
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
};

#endif // WORKER_H

