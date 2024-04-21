
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy(){
    setPixmap(QPixmap(":/img/Images/goblin.png").scaled(50, 50));
    setPos(50, rand()%800);
    dmg = 3;

    x = 450, y = 450;
}

void Enemy::move(){

}
