#include "map.h"
#include "tower.h"
#include "castle.h"
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QMouseEvent>
#include "explosion.h"
#include "wall.h"

void addWalls(QGraphicsScene* sc){
    Wall* w1 = new Wall(); w1->setPos(200, 200);
    Wall* w2 = new Wall(); w2->setPos(300, 200);
    Wall* w3 = new Wall(); w3->setPos(400, 200);
    Wall* w35 = new Wall(); w35->setPos(500, 200);
    Wall* w4 = new Wall(); w4->setPos(500, 300);
    Wall* w5 = new Wall(); w5->setPos(500, 400);
    Wall* w6 = new Wall(); w6->setPos(500, 500);
    Wall* w7 = new Wall(); w7->setPos(400, 500);
    Wall* w8 = new Wall(); w8->setPos(300, 500);
    Wall* w85 = new Wall(); w85->setPos(200, 500);
    Wall* w9 = new Wall(); w9->setPos(200, 400);
    Wall* w10 = new Wall(); w10->setPos(200, 300);
    sc->addItem(w1);
    sc->addItem(w2);
    sc->addItem(w3);
    sc->addItem(w35);
    sc->addItem(w85);
    sc->addItem(w4);
    sc->addItem(w5);
    sc->addItem(w6);
    sc->addItem(w7);
    sc->addItem(w8);
    sc->addItem(w9);
    sc->addItem(w10);
}

Map::Map(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);


    QPixmap mapBackground(":/img/Images/Map.jpg");
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(mapBackground.scaled(800, 800));
    scene->addItem(backgroundItem);
    backgroundItem->setPos(0, 0);

    castle = new Castle();
    tower = new Tower(scene, castle);
    tower->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(tower);
    scene->addItem(castle);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 800);
addWalls(scene);
    // Create the spawn timer
    spawnTimer = new QTimer(this);
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    spawnTimer->start(2000); // Spawn every 2 seconds
}

void Map::spawnEnemy() {
    // Create an enemy
    Enemy* enemy = new Enemy(scene, castle);

    // Add enemy to the list
    enemies.append(enemy);


}

void Map::removeEnemy(Enemy* enemy) {
    // Remove enemy from the list and delete it
    enemies.removeOne(enemy);
    delete enemy;
}

void Map::mousePressEvent(QMouseEvent* e){
    if(true){
        Explosion* exp= new Explosion(scene);
        exp->explode(e->pos().x(), e->pos().y());
        scene->addItem(exp);
        QTimer::singleShot(1000, [exp, this]() {
            scene->removeItem(exp);
            delete exp;
        });
    }
}
