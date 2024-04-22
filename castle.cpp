#include "castle.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include "enemy.h"

Castle::Castle() {
    setPixmap(QPixmap(":/img/Images/Castle.jpg").scaled(61, 61));
    setPos(339, 339);
    health = 100;


}

void Castle::decrease(){
    health--;
    if(isCrushed())
        return;
}

bool Castle::isCrushed(){
    return (health == 0);
}


