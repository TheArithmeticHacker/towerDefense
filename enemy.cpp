#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>

Enemy::Enemy(){
    setPixmap(QPixmap(":/img/Images/goblin.png"));

    QTimer * timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

void Enemy::move(){

}
