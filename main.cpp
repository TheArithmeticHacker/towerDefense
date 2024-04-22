#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include "castle.h"
#include "tower.h"
#include <QDebug>
#include "explosion.h"
#include "enemy.h"
#include "wall.h"
#include <QTimer>

#include "map.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Map map;
    map.show();

    return a.exec();
}
