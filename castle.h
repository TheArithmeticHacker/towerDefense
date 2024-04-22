#ifndef CASTLE_H
#define CASTLE_H
#include <QObject>
#include <QGraphicsPixmapItem>
class Castle : public QObject, public QGraphicsPixmapItem
{
private:
    int health;
public:
    Castle();

    void decrease();

    bool isCrushed();

};

#endif // CASTLE_H
