#include "tower.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include "explosion.h"
#include "castle.h"
#include "enemy.h"

Tower::Tower(QGraphicsScene* scene, Castle* cs) {
    setPixmap(QPixmap(":/img/Images/cannon.jpg").scaled(50, 50));
    setPos(300, 300);
    w = scene;
    QGraphicsPixmapItem* effect_area = new QGraphicsPixmapItem(QPixmap(":/img/Images/Effect.png").scaled(300, 300));
    effect_area->setPos(x() - 125, y() - 125);
    w->addItem(effect_area);
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),this,SLOT(createEnemies(w, cs)));
    time->start(2000);

    primeState = false;
    range = 200;
    AoE = 75;
    coolDown = 3;
}



void Tower::createEnemy(QGraphicsScene* sc, Castle* cs){
    Enemy* ene = new Enemy(sc, cs);
    qDebug("Testing");
    scene()->addItem(ene);
}
