#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QList>
#include <cmath>
#include "castle.h"
#include "wall.h"
#include "explosion.h"

Enemy::Enemy(QGraphicsScene* scene, Castle* targetCastle) : QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/img/Images/goblin.png").scaled(50, 50));
    dmg = 3;
    speed = 100; // Adjust speed as needed
    target = targetCastle;
    scene->addItem(this);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100); // Move every 100 milliseconds

    setPos(QPointF(600, 450));
}

void Enemy::attackCastle(Castle* target) {
    target->decrease();
}

void Enemy::attackWall(Wall* target) {
    target->decrease(dmg);
}

void Enemy::move() {
    // Check for collision with Castle or Wall
    QList<QGraphicsItem*> colliding = collidingItems();
    for (int i = 0; i < colliding.size(); i++) {
        if (typeid(*(colliding[i])) == typeid(Wall)) {
            attackWall(dynamic_cast<Wall*>(colliding[i]));
        } else if (typeid(*(colliding[i])) == typeid(Castle)) {
            attackCastle(dynamic_cast<Castle*>(colliding[i]));
        }
    }

    moveToTarget();
}

void Enemy::moveToTarget() {

    qreal dx = target->pos().x() - pos().x();
    qreal dy = target->pos().y() - pos().y();
    qreal distance = qSqrt(dx * dx + dy * dy);

    if (distance <= 2) {
        // If reached the target, stop moving
        return;
    }

    qreal angle = qAtan2(dy, dx);
    qreal vx = qCos(angle) * speed;
    qreal vy = qSin(angle) * speed;

    setPos(pos().x() + vx, pos().y() + vy);
}
/*
void Enemy::move() {
    setPos(pos().x() - 10, pos().y());
    QList<QGraphicsItem*> colliding = collidingItems();
    for (int i = 0; i < colliding.size(); i++) {
        if (typeid(*(colliding[i])) == typeid(Explosion)) {
            scene()->removeItem(this);
            delete this;
        }
    }
}
*/
