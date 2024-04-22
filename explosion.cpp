#include "explosion.h"
#include <QGraphicsItem>
#include  <QList>
#include "enemy.h"
#include <QDebug>
#include <QTimer>
Explosion::Explosion(QGraphicsScene* scene) {
    setPixmap(QPixmap(":/img/Images/Explosion.jpg").scaled(50, 50));
    w = scene;

}

void Explosion::explode(int x, int y){
    setPos(x, y);
    QTimer * timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}

void Explosion::move(){
    setPos(x() + 1, y()+1);
    QList<QGraphicsItem*> c = collidingItems();
    qDebug("Our");
    for(int i = 0; i < c.size(); i++){
        qDebug("In");
        if(typeid(*(c[i])) == typeid(Enemy)) {
            w->removeItem(c[i]);
            delete c[i]; // Delete the item to properly deallocate memory
        }
    }
}
