#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <QGraphicsPixmapItem>
class Explosion : public QObject, public QGraphicsPixmapItem
{
private:
    QGraphicsScene* w;
public:
    Explosion(QGraphicsScene*);
public slots:
    void explode(int x, int y);
};

#endif // EXPLOSION_H
