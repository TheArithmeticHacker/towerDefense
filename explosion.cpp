#include "explosion.h"
#include <QGraphicsItem>
#include  <QList>
#include "enemy.h"
Explosion::Explosion(QGraphicsScene* scene) {
    setPixmap(QPixmap(":/img/Images/Explosion.jpg").scaled(50, 50));
    w = scene;
}

void Explosion::explode(int x, int y){
    setPos(x, y);
    QList<QGraphicsItem*> colliding = collidingItems();
    for(int i = 0; i < colliding.size(); i++){
        if(typeid(*(colliding[i])) == typeid(Enemy))
            w->removeItem(colliding[i]);
    }
}
