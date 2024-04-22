#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <QGraphicsPixmapItem>
class Explosion : public QObject, public QGraphicsPixmapItem
{
private:
    QGraphicsScene* w;
public:
    Explosion(QGraphicsScene*);

    void explode(int x, int y);
public slots:
    void move();

};

#endif // EXPLOSION_H
