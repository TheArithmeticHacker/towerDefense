#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include "castle.h"
#include "tower.h"
#include <QDebug>
#include "explosion.h"
#include "enemy.h"
#include <QTimer>

class Map : public QGraphicsView {
private:
    QGraphicsScene *scene = new QGraphicsScene;

public:

    Tower* tower;
    Map(QWidget *parent = nullptr) : QGraphicsView(parent) {

        setScene(scene);

        QPixmap mapBackground(":/img/Images/Map.jpg");
        QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(mapBackground.scaled(800, 800));
        scene->addItem(backgroundItem);
        backgroundItem->setPos(0, 0);

        Castle* castleItem = new Castle();
        tower = new Tower(scene);
        tower->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(tower);
        scene->addItem(castleItem);


        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(800, 800);

    }


public slots:
    void mousePressEvent(QMouseEvent* e){
        if(tower->isValid(e->pos().x(), e->pos().y())){
            Explosion* exp= new Explosion(scene);
            exp->explode(e->pos().x(), e->pos().y());
            scene->addItem(exp);
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Map map;
    map.show();

    return a.exec();
}
