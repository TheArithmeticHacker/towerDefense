#include "tower.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include "explosion.h"
#include "enemy.h"

Tower::Tower(QGraphicsScene* scene) {
    setPixmap(QPixmap(":/img/Images/cannon.jpg").scaled(50, 50));
    setPos(300, 300);
    w = scene;
    QGraphicsPixmapItem* effect_area = new QGraphicsPixmapItem(QPixmap(":/img/Images/Effect.png").scaled(300, 300));
    effect_area->setPos(x() - 125, y() - 125);
    w->addItem(effect_area);


    primeState = false;
    range = 200;
    AoE = 75;
    coolDown = 3;
}

bool Tower::isValid(int x1, int y1){
    if(x1 < 450)
        if(x1 > 150)
            if(y1 < 450)
                if(y1 > 150)
                    return true;

    return false;
}



