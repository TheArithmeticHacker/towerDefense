#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QGraphicsItem>
#include "castle.h"
#include "wall.h"



class Enemy: public QObject, public QGraphicsPixmapItem
{
public:
    Enemy(QGraphicsScene*, Castle*);
    int dmg;
    int speed;
    int x, y;
    QGraphicsScene* w;
    Castle* target;

    void attackCastle(Castle*);
    void attackWall(Wall*);
    void moveToTarget();
    void spawnAtRandomPosition();
    void attack();


public slots:
    void move();

};

#endif // ENEMY_H
