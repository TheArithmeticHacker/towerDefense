#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>


class Enemy: public QObject, public QGraphicsPixmapItem
{
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H
