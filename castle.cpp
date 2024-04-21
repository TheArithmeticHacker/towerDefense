#include "castle.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>

Castle::Castle() {
    setPixmap(QPixmap(":/img/Images/Castle.jpg").scaled(61, 61));
    setPos(339, 339);
    health = 100;
}

void Castle::decrease(){
    health--;
}

bool Castle::isCrushed(){
    return (health == 0);
}
