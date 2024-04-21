#include "map.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>

Map::Map(QWidget* parent) : QGraphicsView(parent) {
    QGraphicsScene* scene = new QGraphicsScene;
    setScene(scene);

    QPixmap mapBackground("C:\\Users\\AUC\\Downloads\\ClashofClans\\imagees\\map_background.jpg");
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(mapBackground);
    scene->addItem(backgroundItem);
    backgroundItem->setPos(0, 0);

    QPixmap castle("C:\\Users\\AUC\\Downloads\\ClashofClans\\imagees\\Clan_Castle.png");
    QGraphicsPixmapItem* castleItem = new QGraphicsPixmapItem(castle);
    castleItem->setPos(450, 280);
    scene->addItem(castleItem);



}



