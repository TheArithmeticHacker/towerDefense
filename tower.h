#ifndef TOWER_H
#define TOWER_H
#include <QEvent>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include "castle.h"

class Tower: public QObject, public QGraphicsPixmapItem
{
private:
    int coolDown;
    int range;
    int AoE;
    bool primeState;
    QGraphicsScene* w;
public:
    Tower(QGraphicsScene*, Castle*);



    bool isValid(int x, int y);
public slots:
    void createEnemy(QGraphicsScene*, Castle*);


};

#endif // TOWER_H
