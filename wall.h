#ifndef WALL_H
#define WALL_H
#include <QGraphicsPixmapItem>
class Wall: public QObject, public QGraphicsPixmapItem
{
public:
    Wall();

    void decrease(int);
    void increase();
    int health;
    bool isDestroyed();
};

#endif // WALL_H
