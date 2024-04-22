#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "tower.h"
#include "castle.h"
#include "enemy.h"

class Map : public QGraphicsView {
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Tower* tower;
    Castle* castle;
    QTimer* spawnTimer; // Timer for spawning enemies
    QList<Enemy*> enemies; // List to keep track of spawned enemies

public:
    Map(QWidget *parent = nullptr);
    void removeEnemy(Enemy*);

public slots:
    void spawnEnemy(); // Slot for spawning enemy
    void mousePressEvent(QMouseEvent*);
};

#endif // MAP_H
