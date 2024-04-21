#include "castle.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include "enemy.h"

Castle::Castle() {
    setPixmap(QPixmap(":/img/Images/Castle.jpg").scaled(61, 61));
    setPos(339, 339);
    health = 100;

    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),this,SLOT(createEnemies()));
    time->start(2000);
}

void Castle::decrease(){
    health--;
    if(isCrushed())
        return;
}

bool Castle::isCrushed(){
    return (health == 0);
}

void Castle::createEnemies(){
    Enemy* ene = new Enemy();
    qDebug("Testing");
    scene()->addItem(ene);
}
