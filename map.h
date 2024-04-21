#ifndef MAP_H
#define MAP_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QWidget>
class Map : public QGraphicsView
{
public:
   explicit Map(QWidget* parent = nullptr);
};

#endif // MAP_H
