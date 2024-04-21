#ifndef TOWER_H
#define TOWER_H
#include <QEvent>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsScene>

class Tower: public QObject, public QGraphicsPixmapItem
{
private:
    int coolDown;
    int range;
    int AoE;
    bool primeState;
    QGraphicsScene* w;
public:
    Tower(QGraphicsScene*);



    bool isValid(int x, int y);


};

#endif // TOWER_H
