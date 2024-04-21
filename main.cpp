#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include "castle.h"

class Map : public QGraphicsView {
public:
    Map(QWidget *parent = nullptr) : QGraphicsView(parent) {
        QGraphicsScene *scene = new QGraphicsScene;
        setScene(scene);

        QPixmap mapBackground(":/img/Images/Map.jpg");
        QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(mapBackground.scaled(800, 800));
        scene->addItem(backgroundItem);
        backgroundItem->setPos(0, 0);

        Castle* castleItem = new Castle();
        scene->addItem(castleItem);

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(800, 800);

    }
    };

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Map map;
    map.show();
    return a.exec();
}
